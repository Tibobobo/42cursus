import sys
from bs4 import BeautifulSoup
import pandas as pd
from selenium import webdriver
from selenium.webdriver import By
import requests
import urllib
import time

def isValidUrl(url: str):
    """
    """

def main():
    try:
        assert len(sys.argv) >= 2
        url = sys.argv[1]

    except AssertionError:
        print("Please provide a URL")
        quit()


if __name__ == "__main__":
    main()