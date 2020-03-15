/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init.h
*/

#pragma once

#ifndef INIT_H_
#define INIT_H_

int create_socket(int, int, int);
int init_ifreq(struct ifreq *, int, const char *);
struct sockaddr_ll init_sockaddr_ll(int, struct ifreq);

#endif
