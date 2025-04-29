from duckduckgo_search import DDGS
import requests
from readability import Document
from bs4 import BeautifulSoup
import google.generativeai as genai

# Configure the API key
genai.configure(api_key="AIzaSyCajkR1psr7Buvnmw9ho1DgrPFBQT3ercw")


def get_article_links(query, num=3):
    print(f"\nSearching DuckDuckGo for: {query}")
    results = []
    with DDGS() as search: # we use with statement to ensure the session is closed properly
        for r in search.text(query, max_results=num): #search.text() is a dictionary containing href, title, body, etc.
            results.append(r["href"])
    return results

def extract_article_text(url):
    try:
        print(f"\n📄 Fetching: {url}")
        response = requests.get(url, timeout=10)
        response.raise_for_status()

        doc = Document(response.text)
        html = doc.summary()
        soup = BeautifulSoup(html, "html.parser")
        text = soup.get_text(separator="\n").strip()

        return text
    except Exception as e:
        print(f"❌ Failed to extract article: {e}")
        return ""

def summarize_text(text):
    if not text:
        return "No content to summarize."
    
    prompt = f"Summarize this article in 5 bullet points:\n\n{text[:4000]}"

    try:
        model = genai.GenerativeModel("gemini-pro")
        response = model.generate_content(prompt)
        return response.text.strip()
    except Exception as e:
        return f"❌ Error during Gemini summarization: {e}"

    
if __name__ == "__main__":

    query = input("Enter your query: ")

    links = get_article_links(query+" news")

    if links:
        print("Links:")
        for link in links:
            print(link)

            text = extract_article_text(link)

            if text:
                print("\nArticle text:")
                summ = summarize_text(text)
                print(summ)  # Print the first 1000 characters of the article text
            else:
                print("No article text found.")
            
            print("\n" + "="*80)  # Separator between articles
