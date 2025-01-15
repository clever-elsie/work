import sys
import requests
from bs4 import BeautifulSoup

def fetch_pre_contents(url):
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
            'Accept-Language': 'en-US,en;q=0.9',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8'
        }
        session = requests.Session()
        session.headers.update(headers)
        response = session.get(url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        
        pre_contents = []
        h3_tags = soup.find_all('h3')

        for h3_tag in h3_tags:
            if '入力例' in h3_tag.text:
                next_sibling = h3_tag.find_next_sibling()
                while next_sibling:
                    if next_sibling.name == 'pre':
                        pre_contents.append(next_sibling.text)
                        break
                    next_sibling = next_sibling.find_next_sibling()

        return pre_contents
    except requests.exceptions.RequestException as e:
        print(f"Error fetching URL: {e}")
        return []

def read_url_from_file(file_path):
    try:
        with open(file_path, 'r') as file:
            url = file.read().strip()
            return url
    except Exception as e:
        print(f"Error reading file {file_path}: {e}", file=sys.stderr)
        return None

def save_contents_to_files(contents):
    for index, content in enumerate(contents):
        filename = f"/dev/shm/default_{index}.in"
        try:
            with open(filename, 'w') as file:
                file.write(content)
                file.write('\n')
        except Exception as e:
            print(f"Error writing sample {filename}: {e}", file=sys.stderr)

if __name__ == "__main__":
    file_path = "/dev/shm/url"
    url = read_url_from_file(file_path)
    if not url:
        print("No URL found", file=sys.stderr)
        exit(1)
    contents = fetch_pre_contents(url)
    save_contents_to_files(contents)
