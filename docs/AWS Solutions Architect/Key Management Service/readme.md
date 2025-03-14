---
sidebar_position: 7
title: Key Management Service
---

# Key Management Service

## Introduction

KMS is a service inside AWS that is used to store and manage cryptographic keys. It is used to do symmeteric and assymteric encryption and decryption. Nothing in the KMS product is stored as a plain text. Everyhting is stored in an encrypted format. KMS can encrypt and decrypt data which is upto 4KB in size. KMS encryption and decryption has passed the FIPS 140-2 standard.

1. KMS keys are region scoped.
2. You can create aliases to keys.

### Data Encryption Keys (DEKs)

To get over the limitation of KMS's 4KB limit for data, we can use data encryption keys. DEK's are keys generated by KMS that the client can use to encrypt and decrypt the data they want to. DEKs have two parts:

1. Plain Text
2. Cipher Text

When encrypting data, we use the plain text version of the key and once encrypted, we discard the plain text version and keep the encrypted data and the cipher text together. For decrypting we can use the 2.

## KMS Policies and Security

1. By default, each key created within KMS has a key policy attached to it which is a resource policy.
2. We should use a combination of key policies and Identity policies to grant AWS identities access to use KMS.
