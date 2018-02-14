/*

Arduino library for ClosedCube I2C-driver wrapper

---

The MIT License (MIT)

Copyright (c) 2018 ClosedCube Limited

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifndef _CLOSEDCUBE_I2C_h
#define _CLOSEDCUBE_I2C_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
	#include <Wire.h>
	#define CC_ARDUINO 1

#else
	#include "WProgram.h"
#endif


#define CC_I2C_RW_DELAY_MS 5
#define CC_I2C_ERROR_NOT_DEFINED 0xFF
#define CC_I2C_ERROR_REQ_INCORRECT 0xA0
#define CC_I2C_OK 0x00

namespace ClosedCube
{
	namespace Driver
	{

		class I2CDevice
		{

		public:

			I2CDevice(uint8_t address);

			byte readByte();
			short readWord();
			int readInt();
			void readBytes(char* buf, uint8_t size);

			void writeByte(byte value);
			void writeByte(byte value, bool stop);
			void writeWord(short value);
			void writeWord(short value, bool stop);
			void writeInt(int value);
			void writeInt(int value, bool stop);

			byte readByteFromReg(uint8_t reg, byte delay_ms);
			byte readByteFromReg(uint8_t reg);

			short readWordFromReg(uint8_t reg, byte delay_ms);
			short readWordFromReg(uint8_t reg);

			void writeByteToReg(uint8_t reg, byte value);
			void writeWordToReg(uint8_t reg, short value);
			

			uint8_t lastErrorCode();

		private:

			uint8_t _address;
			uint8_t _errorCode;

			void clearError();
		};

	};
};

#endif

