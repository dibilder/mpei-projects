import sqlite3
import os
from flask import Flask, render_template, request, flash, g, abort, url_for, redirect
from FDataBase import FDataBase
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import LoginManager, login_user, login_required, logout_user, current_user
from UserLogin import UserLogin

# Configuration
DATABASE = '/tmp/flsite.db'
DEBUG = True
SECRET_KEY = 'fdsjkhk4hhbgfds787789f'

app = Flask(__name__)
app.config.from_object(__name__)
app.config.update(dict(DATABASE=os.path.join(app.root_path, 'flsite.db')))

login_manager = LoginManager(app)
login_manager.login_view = 'login'
login_manager.login_messag = "Please log in to access this page."
login_manager.login_message_category = "error"

@login_manager.user_loader
def load_user(user_id):
    print("load_user")
    return UserLogin().fromDB(user_id, dbase)

def connect_db():
    conn = sqlite3.connect(app.config['DATABASE'])
    conn.row_factory = sqlite3.Row
    return conn


def create_db():
    db = connect_db()
    with app.open_resource('sq_db.sql', mode='r') as f:
        db.cursor().executescript(f.read())
    db.commit()
    db.close()


def get_db():
    if not hasattr(g, 'link_db'):
        g.link_db = connect_db()
    return g.link_db


dbase = None  # global


@app.before_request
def before_request():
    """Connect to BD before anyone request"""
    global dbase
    db = get_db()
    dbase = FDataBase(db)


@app.teardown_appcontext
def close_db(error):
    if hasattr(g, 'link_db'):
        g.link_db.close()



@app.route("/")
@login_required
def index():
    departments = dbase.getAllDepartments()
    return render_template('default.html', menu=dbase.getMenu(), posts=dbase.getRequestPreview(), departments=departments)


@app.route("/add_request", methods=["POST", "GET"])
@login_required
def addRequest():
    priorities = dbase.getAllPriorities()
    statuses = dbase.getAllStatuses()
    users = dbase.getAllUsers()
    departments = dbase.getAllDepartments()
    URL = ""
    if request.method == "POST":
        if len(request.form['name']) > 4 and len(request.form['text']) > 4:

            URL = dbase.getDepartmentURL(request.form['department_id']) + str(int(dbase.getMaxRequestID()) + 1)

            res = dbase.addRequest(request.form['name'], request.form['text'], request.form["priority_id"], request.form['status_id'], URL, request.form['assignee_id'], request.form['department_id'])
            if not res:
                flash('Add request error', category='error')
            else:
                flash('Request added successfully', category='success')
        else:
            flash('Add request error', category='error')
    return render_template('add_request.html', menu=dbase.getMenu(), title="Request adding", priorities=priorities, statuses=statuses, users=users, departments=departments)


@app.route("/requestsForDepartment/<department_id>")
@login_required
def showDepRequests(department_id):
    department = dbase.getDepartment(department_id)
    priorities = dbase.getAllPriorities()
    statuses = dbase.getAllStatuses()
    users = dbase.getAllUsers()

    statusesCount = len(statuses)
    requests = []
    for i in range(statusesCount):
        requests.append(dbase.getRequestByDepartment(department_id, (i+1)))



    return render_template('requests_for_department.html', menu=dbase.getMenu(), requests=requests, department=department, statuses=statuses, priorities = priorities, users = users)

@app.route("/request/<alias>")
@login_required
def showRequest(alias):
    title, text, priority_id, status_id, url, assignee_id, department_id = dbase.getRequest(alias)
    priority = dbase.getPriority(priority_id)
    status = dbase.getStatus(status_id)
    assignee = dbase.getUser(assignee_id)
    department = dbase.getDepartment(department_id)
    if not title:
        abort(404)
    return render_template('request.html', menu=dbase.getMenu(), title=title, post=text, priority=priority, status=status, assignee=assignee[1], department=department, number=url)

@app.route("/deleteRequest/<alias>")
@login_required
def delRequest(alias):
    title = "Delete request"
    res = dbase.delRequest(alias)
    print(res)
    if not res:
        flash('Delete request error', category='error')
    else:
        flash('Request deleted successfully', category='success')
    return render_template('del_request.html', menu=dbase.getMenu(), title=title)

@app.route("/editRequest/<alias>", methods=["POST", "GET"])
@login_required
def editRequest(alias):
    title, text, priority_id, status_id, url, assignee_id, department_id = dbase.getRequest(alias)
    priorities = dbase.getAllPriorities()
    statuses = dbase.getAllStatuses()
    users = dbase.getAllUsers()
    departments = dbase.getAllDepartments()
    if not title:
        abort(404)
    if request.method == "POST":
        if len(request.form['title']) > 4 and len(request.form['text']) > 4:
            res = dbase.updateRequest(request.form['title'], request.form['text'], request.form['url'], request.form['priority_id'], request.form['status_id'], request.form['assignee_id'], request.form['department_id'])
            if not res:
                flash('Update request error', category='error')
            else:
                flash('Request updated successfully', category='success')
                # TODO: Lists of priority and status doesn't reload selected value
                return render_template('edit_request.html', menu=dbase.getMenu(), title=request.form['title'], text=request.form['text'],
                                       priority=request.form['priority_id'], status=request.form['status_id'], assignee= request.form['assignee_id'], department=['department_id'],
                                       number=request.form['url'], priorities=priorities, statuses=statuses, users=users, departments=departments)
        else:
            flash('Add request error', category='error')
    return render_template('edit_request.html', menu=dbase.getMenu(), title=title, text=text, priority=priority_id, status=status_id, assignee=assignee_id, department=department_id,
                           number=url, priorities=priorities, statuses=statuses, users=users, departments=departments)


@app.route("/login", methods=["POST", "GET"])
def login():
    if current_user.is_authenticated:
        return redirect(url_for('profile'))

    if request.method == "POST":
        print(request.form['email'])
        user = dbase.getUserByEmail(request.form['email'])
        if user and check_password_hash(user['psw'], request.form['psw']):
            userlogin = UserLogin().create(user)
            rm = True if request.form.get('remainme') else False
            login_user(userlogin, remember=rm)
            return redirect(request.args.get("next") or url_for("profile"))

        flash("Login or Password was incorrect", "error")

    return render_template('login.html', menu=dbase.getMenu(), title="Authorization")


@app.route("/register", methods=["POST", "GET"])
def register():
    if request.method == "POST":
        if len(request.form['name']) > 4 and len(request.form['email']) > 4 \
                and len(request.form['psw']) > 4 and request.form['psw'] == request.form['psw2']:
            hash = generate_password_hash(request.form['psw'])
            res = dbase.addUser(request.form['name'], request.form['email'], hash)
            if res:
                flash("Registration succeed", "success")
                return redirect(url_for('login'))
            else:
                flash("Error while adding into DB", "error")
        else:
            flash("You have some mistakes in required fields")
    return render_template('register.html', menu=dbase.getMenu(), title="Registration")


@app.route('/logout')
@login_required
def logout():
    logout_user()
    flash("Вы вышли из аккаунта", "success")
    return redirect(url_for('login'))


@app.route('/profile')
@login_required
def profile():
    id, name, email, psw, time = dbase.getUser(current_user.get_id())
    return render_template('profile.html', menu=dbase.getMenu(), title="Profile", id=id, name=name, email=email, time=time)


if __name__ == "__main__":
    app.run(debug=True)
