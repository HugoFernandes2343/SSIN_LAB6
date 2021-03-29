import binascii

prefix = "0001"
hash = "d151c37125d9be7cde130ea3f0cc7f008f3f97b13b6aa438c87578e02ca957d5"
A = "3031300d060960864801650304020105000420"
total_len = 256
pad_len = total_len - 1 - (len(A) + len(prefix) + len(hash)) // 2
padded = prefix + "ff" * pad_len + "00" + A + hash

with open("cenas.bin", "wb") as output_file:
    output_file.write(binascii.unhexlify(padded))

print(padded)