/*
** EPITECH PROJECT, 2018
** parameters.h
** File description:
** parameters.h
*/

#pragma once

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

void get_ip(unsigned char *, const char *);
void get_mac_address(unsigned char *, const char *);
int good_addr(const unsigned char *, int);
void get_flags(data_t *, char **);
data_t get_parameters(int, char **);

#endif
