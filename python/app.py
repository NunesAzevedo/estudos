from flask import Flask 
from datetime import datetime 
from dorian import dorian_func  # Importe a função dorian_func do arquivo dorian.py

app = Flask(__name__) 


@app.route('/')
def run_dorian():
    dorian_func()  # Chame a função dorian_func do arquivo dorian.py
    return 'Animation completed!'

if __name__ == '__main__': 
    app.run(debug=True)
