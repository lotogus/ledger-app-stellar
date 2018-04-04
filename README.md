# Casinocoin app for the Ledger Nano S and Ledger Blue

## Introduction

This is a wallet app for the [Ledger Nano S](https://www.ledgerwallet.com/products/ledger-nano-s) and [Ledger Blue](https://www.ledgerwallet.com/products/ledger-blue) that makes it possible to store your [Casinocoin](https://www.casinocoin.org/)-based assets on those devices.

A companion [Javascript library](https://github.com/LedgerHQ/ledgerjs) is available to communicate with this app.

To learn how to use this library you can take look at the [demo project](https://github.com/lenondupe/ledgerjs-casinocoin). 

## Building and installing

To build and install the app on your Nano S or Blue you must set up the Ledger Nano S or Blue build environment. Please follow the Getting Started instructions at the [Ledger Nano S github repository](https://github.com/LedgerHQ/ledger-nano-s).

Alternatively, you can set up the Vagrant Virtualbox Ledger environment maintained [here](https://github.com/fix/ledger-vagrant). This sets up an Ubuntu virtual machine with the Ledger build environment already set up. Note that if you are on a Mac, at the time of this writing this seems to be the only way to build and load the app.

The command to compile and load the app onto the device is:

```$ make load```

To remove the app from the device do:

```$ make delete```

## Testing

The `./test` directory contains files for testing the xdr transaction parser and some printing utilities. To build and execute the tests run `./test.sh`.

### XDR parsing

When a transaction is to be signed it is sent to the device as an [XDR](https://tools.ietf.org/html/rfc1832) serialized binary object. To show the transaction details to the user on the device this binary object must be read. This is done by a purpose-built parser shipped with this app.

## Key pair validation

The operation to retrieve the public key implements an optional keypair verification method. Along with the request to retrieve the public key a small message is sent that is to be signed by the device. Back on the host the returned signature can be checked against the returned public key. This is to guard against incompatibility between the keypairs generated by the Ledger device and the ones expected by the Casinocoin network, whatever the reason for this might be. The extra precaution prevents users from sending funds to an address they are not able to sign transactions for.

## Troubleshooting

#### TypeError: argument must be string or read-only buffer, not bytearray

After installing a new development environment I ran into this issue while loading the app. It could be related to an incompatible python version. I got around it by editing hexLoader.py. It seems the icon sometimes causes the data type of data object to be converted from string to byte array. On line 148 change
```python
data += struct.pack('>B', len(icon)) + icon
```  
to 
```python
data += struct.pack('>B', len(icon)) + str(icon)
```
