from flask import Flask, render_template, request, redirect, url_for, session, g
import sqlite3
import pandas as pd
import smtplib
from email.message import EmailMessage

app = Flask(__name__)
app.secret_key = 'your_secret_key'  # Change this to a strong secret key

# Database setup
def init_db():
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY,
            username TEXT NOT NULL,
            password TEXT NOT NULL
        )
    ''')
    conn.commit()
    conn.close()

init_db()

def get_db():
    if 'db' not in g:
        g.db = sqlite3.connect('users.db', check_same_thread=False)
    return g.db

@app.teardown_appcontext
def close_db(error):
    if hasattr(g, 'db'):
        g.db.close()

# Routes
@app.route('/')
def index():
    if 'username' in session:
        return redirect(url_for('dashboard'))
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    conn = get_db()
    cursor = conn.cursor()
    cursor.execute('SELECT * FROM users WHERE username=? AND password=?', (username, password))
    user = cursor.fetchone()
    
    if user:
        session['username'] = user[1]
        return redirect(url_for('dashboard'))
    else:
        return "Invalid credentials."

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        
        conn = get_db()
        cursor = conn.cursor()
        cursor.execute('INSERT INTO users (username, password) VALUES (?, ?)', (username, password))
        conn.commit()
        
        return redirect(url_for('index'))
    
    return render_template('register.html')

@app.route('/dashboard')
def dashboard():
    if 'username' in session:
        return render_template('dashboard.html', username=session['username'])
    else:
        return redirect(url_for('index'))

@app.route('/export')
def export():
    if 'username' in session:
        conn = get_db()
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM users')
        data = cursor.fetchall()
        df = pd.DataFrame(data, columns=['id', 'username', 'password'])
        df.to_excel('user_data.xlsx', index=False)
        
        msg = EmailMessage()
        msg.set_content('Attached is the user data Excel file.')
        msg['Subject'] = 'User Data'
        msg['From'] = 'sakethveera321@gmail.com'
        msg['To'] = 'sakethveera1234@gmail.com'
        
        with open('user_data.xlsx', 'rb') as file:
            msg.add_attachment(file.read(), maintype='application', subtype='xlsx', filename='user_data.xlsx')
        
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
            smtp.login('sakethveera321@gmail.com', 'scbjiwwrxmsbxqoj')
            smtp.send_message(msg)
        
        return "Data exported and shared via email."
    else:
        return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
