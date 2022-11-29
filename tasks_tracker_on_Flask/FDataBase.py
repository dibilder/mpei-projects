import sqlite3
import math
import time


class FDataBase:
    """This class implements """
    def __init__(self, db):
        self.__db = db
        self.__cur = db.cursor()

    def getMenu(self):
        sql = '''SELECT * FROM mainmenu'''
        try:
            self.__cur.execute(sql)
            res = self.__cur.fetchall()
            if res: return res
        except:
            print("Error reading from DB")
        return []

    def addRequest(self, title, text, priority_id, status_id, url, assignee_id, department_id):
        try:
            self.__cur.execute(f"SELECT COUNT() as 'count' FROM requests WHERE url LIKE '{url}'")
            res = self.__cur.fetchone()
            if res['count'] > 0:
                print("Request with the same URL already exist")
                return False

            tm = math.floor(time.time())
            self.__cur.execute("INSERT INTO requests VALUES(NULL, ?, ?, ?, ?, ?, ?, ?, ?)", (title, text, priority_id, status_id, url, assignee_id, department_id, tm))
            self.__db.commit()
        except sqlite3.Error as e:
            print("Error while adding post into DB " + str(e))
            return False
        return True

    def getRequest(self, alias):
        try:
            self.__cur.execute(f"SELECT title, text, priority_id, status_id, url, assignee_id, department_id FROM "
                               f"requests WHERE url "
                               f"LIKE '{alias}' LIMIT 1")
            res = self.__cur.fetchone()
            if res:
                return res
        except sqlite3.Error as e:
            print("Error while getting post from DB" + str(e))

        return False, False

    def getRequestByDepartment(self, department, status):
        try:
            self.__cur.execute(f"SELECT title, text, priority_id, status_id, url, assignee_id, department_id FROM "
                               f"requests WHERE department_id "
                               f"== {department} and status_id == {status}")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting requests from DB" + str(e))

    def delRequest(self, alias):
        try:
            res = self.__cur.execute(f"DELETE FROM requests WHERE url LIKE '{alias}'")
            self.__db.commit()
            return True
        except sqlite3.Error as e:
            return False
            print("Error while deleting from DB" + str(e))
        return False

    def getPriority(self, priority_id):
        try:
            self.__cur.execute(f"SELECT * FROM priorities WHERE id = {priority_id}")
            res = self.__cur.fetchone()
            if res:
                return res[1]
        except sqlite3.Error as e:
            print("Error while getting priority from DB" + str(e))

        return False, False

    def getDepartment(self, department_id):
        try:
            self.__cur.execute(f"SELECT * FROM departments WHERE id = {department_id}")
            res = self.__cur.fetchone()
            if res:
                return res[1]
        except sqlite3.Error as e:
            print("Error while getting department from DB" + str(e))

        return False, False

    def getAllPriorities(self):
        try:
            self.__cur.execute("SELECT * FROM priorities")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting priority from DB" + str(e))

        return False

    def getAllStatuses(self):
        try:
            self.__cur.execute("SELECT * FROM statuses")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting status from DB" + str(e))

        return False

    def getAllDepartments(self):
        try:
            self.__cur.execute("SELECT * FROM departments")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting departments from DB" + str(e))

        return False

    def getAllUsers(self):
        try:
            self.__cur.execute("SELECT * FROM users")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting status from DB" + str(e))

        return False

    def getStatus(self, status_id):
        try:
            self.__cur.execute(f"SELECT * FROM statuses WHERE id = {status_id}")
            res = self.__cur.fetchone()
            if res:
                return res[1]
        except sqlite3.Error as e:
            print("Error while getting priority from DB" + str(e))

        return False, False

    def getDepartmentURL(self, department_id):
        try:
            self.__cur.execute(f"SELECT * FROM departments WHERE id = {department_id}")
            res = self.__cur.fetchone()
            if res:
                return res[3]
        except sqlite3.Error as e:
            print("Error while getting department URL from DB" + str(e))

        return False

    def getMaxRequestID(self):
        try:
            self.__cur.execute("SELECT MAX(id) AS max FROM requests")
            res = self.__cur.fetchone()
            if res:
                return res['max']
        except sqlite3.Error as e:
            print("Error while getting max ID from DB" + str(e))

    def updateRequest(self, title, text, url, priority_id, status_id, assignee_id, department_id):
        try:
            self.__cur.execute("UPDATE requests SET title = ? , text = ? , priority_id = ? , status_id= ? , "
                               "assignee_id = ?, department_id = ?  WHERE "
                               "url LIKE ?", (title, text, priority_id, status_id, assignee_id, department_id, url))
            self.__db.commit()
        except sqlite3.Error as e:
            print("Error while updating request from DB" + str(e))
            return False
        return True


    def getRequestPreview(self):
        try:
            self.__cur.execute(f"SELECT id, title, text, url, department_id, status_id FROM requests ORDER BY time DESC")
            res = self.__cur.fetchall()
            if res: return res
        except sqlite3.Error as e:
            print("Error while getting post from DB" + str(e))

        return []

    def addUser(self, name, email, hpsw):
        try:
            self.__cur.execute(f"SELECT COUNT() as 'count' FROM users WHERE email LIKE '{email}'")
            res = self.__cur.fetchone()
            if res['count'] > 0:
                print("Users with the same email already exist")
                return False

            tm = math.floor(time.time())
            self.__cur.execute("INSERT INTO users VALUES(NULL, ?, ?, ?, ?)", (name, email, hpsw, tm))
            self.__db.commit()
        except sqlite3.Error as e:
            print("Error while adding user into DB " + str(e))
            return False
        return True

    def getUser(self, user_id):
        try:
            self.__cur.execute(f"SELECT * FROM users WHERE id = {user_id} LIMIT 1")
            res = self.__cur.fetchone()
            if not res:
                print("Can't find this user in DB")
                return False

            return res
        except sqlite3.Error as e:
            print("Error while getting data from DB" + str(e))

        return False

    def getUserByEmail(self, email):
        try:
            self.__cur.execute(f"SELECT * FROM users WHERE email = '{email}' LIMIT 1")
            res = self.__cur.fetchone()
            if not res:
                print("Can't find this user in DB")
                return False

            return res
        except sqlite3.Error as e:
            print("Error while getting data from DB " + str(e))

        return False
