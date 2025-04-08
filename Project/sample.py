import requests
from bs4 import BeautifulSoup

url = 'https://www.bbc.com/news'
headers = {'User-Agent': 'Mozilla/5.0'}
response = requests.get(url, headers=headers)

soup = BeautifulSoup(response.content, 'html.parser')

title = soup.find('h1')
paragraphs = soup.find_all('p')

print("Title:", title.text if title else "Not found")
print("Text:\n")
for p in paragraphs[:10]:
    print(p.text)
