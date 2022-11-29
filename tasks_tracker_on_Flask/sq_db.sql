CREATE TABLE IF NOT EXISTS mainmenu (
	id integer PRIMARY KEY AUTOINCREMENT,
	title text NOT NULL,
	url text NOT NULL
);

CREATE TABLE IF NOT EXISTS requests (
id integer PRIMARY KEY AUTOINCREMENT, 
title text NOT NULL,
text text NOT NULL,
priority_id integer NOT NULL,
status_id integer NOT NULL,
url text NOT NULL,
assignee_id integer,
department_id integer,
time integer NOT NULL
);


CREATE TABLE IF NOT EXISTS users (
id integer PRIMARY KEY AUTOINCREMENT, 
name text NOT NULL,
email text NOT NULL,
psw text NOT NULL,
time integer NOT NULL
);

CREATE TABLE IF NOT EXISTS statuses (
id integer PRIMARY KEY AUTOINCREMENT, 
name text NOT NULL
);

CREATE TABLE IF NOT EXISTS priorities (
id integer PRIMARY KEY AUTOINCREMENT, 
name text NOT NULL
);

CREATE TABLE IF NOT EXISTS departments (
id integer PRIMARY KEY AUTOINCREMENT, 
name text NOT NULL,
description text,
URL text
);
