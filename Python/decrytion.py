S = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?."

L = [
    "qeFIP?eGSeECNNS,",
    "5coOMXXcoPSZIWoQI,",
    "avnl1olyD4l'ylDohww6DhzDjhuDil,",
    "z.GM?.cEQc. 70c.7KcKMKHA9AGFK,",
    "?MFYp2pPJJUpZSIJWpRdpMFY,",
    "ZqH8sl5HtqHTH4s3lyvH5zH5spH4t pHzqHlH3l5K",
    "Zfbi,!tif!xpvme!qspcbcmz!fbu!nfA"
]

W = [
    'the', 'this', 'and', 'that', 'you', 'for', 'with', 'have', 'not',
    'are', 'your', 'from', 'eat', 'probably', 'under ', 'love', 'kitty ',
    'happy', 'though'
]

for i in range(len(L)):
    text = L[i]
    found = False
    for k in range(len(S)):
        new = ''
        for j in range(len(text)):
            c = text[j]
            if c in S:
                idx = S.index(c)
                new += S[(idx - k) % len(S)]
            else:
                new += c
        if any(w in new.lower() for w in W):
            print("Decrypted text:", new)
            print("Key:", k)
            found = True
            break
    if not found:
        print("No proper decryption")
