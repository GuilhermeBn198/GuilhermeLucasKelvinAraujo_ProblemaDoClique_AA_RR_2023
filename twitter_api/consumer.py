from datetime import datetime
import json
import os
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

# Retrieve the value of an environment variable
API_KEY = os.getenv('API_KEY')
API_SECRET_KEY = os.getenv('API_SECRET_KEY')
BEARER_TOKEN = os.getenv('BEARER_TOKEN')
ACCESS_TOKEN = os.getenv('ACCESS_TOKEN')
ACCESS_TOKEN_SECRET = os.getenv('ACCESS_TOKEN_SECRET')


# Use the value of the environment variable
print(API_KEY)
print(API_SECRET_KEY)
print(ACCESS_TOKEN)
print(ACCESS_TOKEN_SECRET)
print(BEARER_TOKEN)