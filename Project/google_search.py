from duckduckgo_search import DDGS
import requests
from readability import Document
from bs4 import BeautifulSoup

def get_article_links(query, num=3):
    print(f"\nSearching DuckDuckGo for: {query}")
    results = []
    with DDGS() as search: # we use with statement to ensure the session is closed properly
        for r in search.text(query, max_results=num): #search.text() is a dictionary containing href, title, body, etc.
            results.append(r["href"])
    return results

    
if __name__ == "__main__":

    quesry = input("Enter your query: ")

    links = get_article_links(quesry+" news")

    if links:
        print("Links:")
        for link in links:
            print(link)