#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov  4 00:33:14 2018

@author: Javier Alejandro Acevedo Barroso
"""


import numpy as np
import matplotlib
matploblib.use("Agg")
import matplotlib.pyplot as plt

def gaussiana(x,mu,sigma):
    return (1/(sigma*np.sqrt(2*np.pi)))*np.exp(-0.5*((x-mu)/sigma)**2)


constantes = np.loadtxt("stan.dat")
puntos = np.loadtxt("sample.dat")
x = np.linspace(constantes[1]-3.5*constantes[2],constantes[1]+3.5*constantes[2],int(constantes[0]))

plt.plot(x,gaussiana(x,constantes[1],constantes[2]))
plt.hist(puntos,bins=int(constantes[0]//12),density=True)
plt.savefig("sample.pdf")

