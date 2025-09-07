#!/usr/bin/env python3
import sys, os
import requests
from bs4 import BeautifulSoup

def fetch_problem(prob_id: str):
    url = f"https://www.acmicpc.net/problem/{prob_id}"
    headers = {
        "User-Agent": (
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
            "AppleWebKit/537.36 (KHTML, like Gecko) "
            "Chrome/110.0.0.0 Safari/537.36"
        ),
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
        "Accept-Language": "en-US,en;q=0.9",
        "Referer": "https://www.acmicpc.net/",
        "Connection": "keep-alive",
    }
    with requests.Session() as s:
        r = s.get(url, headers=headers)
        r.raise_for_status()
        html = r.text

        return html

def extract_samples(html: str):
    soup = BeautifulSoup(html, "html.parser")
    samples = soup.find_all("pre", class_="sampledata")
    # samples alternate: input, output, input, output...
    ios = []
    for i in range(0, len(samples), 2):
        in_text = samples[i].get_text("\n").strip()
        out_text = samples[i+1].get_text("\n").strip()
        ios.append((in_text, out_text))
    return ios

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 test/test_generator.py PROB")
        sys.exit(1)
    prob_id = sys.argv[1]

    html = fetch_problem(prob_id)
    ios = extract_samples(html)

    outdir = os.path.join("testcases", prob_id)
    os.makedirs(outdir, exist_ok=True)

    for idx, (inp, outp) in enumerate(ios, 1):
        with open(os.path.join(outdir, f"sample{idx}.in"), "w") as f:
            f.write(inp + "\n")
        with open(os.path.join(outdir, f"sample{idx}.out"), "w") as f:
            f.write(outp + "\n")

    print(f"Fetched {len(ios)} samples for problem {prob_id} into {outdir}/")

if __name__ == "__main__":
    main()
