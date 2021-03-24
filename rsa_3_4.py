n = int(0xDCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5)
d = int(0x74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D)
M1 = int.from_bytes( b'I owe you $2000.', byteorder='big')
M2 = int.from_bytes( b'I owe you $3000.', byteorder='big')

signature_1 = pow(M1, d, n)
signature_2 = pow(M2, d, n)

print('Signature 1: ', hex(signature_1))
print('Signature 2: ', hex(signature_2))