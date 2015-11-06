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

#ifndef __AARNI_SHA384_H__
#define __AARNI_SHA384_H__

#include <QByteArray>

#include "const.h"

namespace Aarni
{

// This class implements SHA-384 [1], and there is no known attack against it.
//
// References:
//  [1] http://csrc.nist.gov/publications/fips/fips180-3/fips180-3_final.pdf
class SHA384
{
public:
    // Constructor.
    SHA384();

    // Reset the digest to the initial state.
    void reset();

    // Update the digest.
    //
    // Parameters:
    //  in - the data to be hashed
    void update(const QByteArray& in);

    // Complete the hash computation and return the digest.
    //
    // Parameters:
    //  out - the digest
    void digest(QByteArray& out);

private:
    // The constants used.
    static quint64 rcon_[80];

    // The variables used.
    quint64 h0_, h1_, h2_, h3_, h4_, h5_, h6_, h7_; // the chaining variables
    qint8 buffer_[128];                             // the buffer to hold the last block
    qint32 bufLen_;                                 // the length of data in the buffer
    quint64 total_;                                 // the total number of data hashed

    // Compute the digest of a single block.
    void hashBlock(const qint8* const in);
};

}

#endif // __AARNI_SHA384_H__
