/*
 * Aarni is a simple and easy-to-use file encryptor.
 * Copyright (C) 2009 Xizhi Zhu <xizhi.zhu@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation,
 * or attached in the package as the LICENSE file.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#ifndef __AARNI_CONST_H__
#define __AARNI_CONST_H__


#include <QString>


// Constants used.
const quint16 FILE_MAGIC = 0x4541;
const quint8 FILE_VERSION = 0x02;
const quint8 PROTOCOL_VERSION = 0x01;
const quint8 FILE_FLAG_NONE = 0x00;


// Error codes.
const quint32 ERROR_SUCCESS = 0;

const quint32 ERROR_NOT_INITIALIZED = 100;
const quint32 ERROR_DATA_UNIT_TOO_LONG = 101;
const quint32 ERROR_DATA_UNIT_TOO_SHORT = 102;
const quint32 ERROR_INVALID_KEY_LENGTH = 103;
const quint32 ERROR_INVALID_TWEAK_LENGTH = 104;

const quint32 ERROR_EMPTY_PASSWORD = 200;
const quint32 ERROR_SOURCE_NOT_EXIST = 201;
const quint32 ERROR_DESTINATION_EXISTED = 202;
const quint32 ERROR_ALREADY_RUNNING = 203;

const quint32 ERROR_INVALID_FILE_FORMAT = 300;
const quint32 ERROR_CORRUPTED_FILE = 301;


#endif // __AARNI_CONST_H__
