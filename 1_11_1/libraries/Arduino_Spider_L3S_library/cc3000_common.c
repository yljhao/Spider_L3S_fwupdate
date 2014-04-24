/*****************************************************************************
*
*  cc3000_common.c.c  - CC3000 Host Driver Implementation.
*  Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
*
*
*  This library porting from CC3000 host driver, which works with 
*  Spider_L3S WiFi module.
*
*  Spider_L3S wifi module is developed by Funmaker, we are actively 
*  involved in Taiwan maker community, and we aims to support makers 
*  to make more creative projects. 
*
*  You can support us, by buying this wifi module, and we are looking
*  forward to see your awesome projects!
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/
//*****************************************************************************
//
//! \addtogroup common_api
//! @{
//
//*****************************************************************************
/******************************************************************************
 *
 * Include files
 *
 *****************************************************************************/
#include "cc3000_common.h"
#include "socket.h"
#include "wlan.h"
#include "evnt_handler.h"

//*****************************************************************************
//
//!  __error__
//!
//!  @param  pcFilename - file name, where error occurred
//!  @param  ulLine     - line number, where error occurred
//!
//!  @return none
//!
//!  @brief stub function for ASSERT macro
//
//*****************************************************************************

void
__error__(char *pcFilename, unsigned long ulLine)
{
    //TODO full up function
    (void)(pcFilename);
    (void)(ulLine);
}



//*****************************************************************************
//
//!  UINT32_TO_STREAM_f
//!
//!  @param  p       pointer to the new stream
//!  @param  u32     pointer to the 32 bit
//!
//!  @return               pointer to the new stream
//!
//!  @brief                This function is used for copying 32 bit to stream
//!						   while converting to little endian format.
//
//*****************************************************************************

unsigned char* UINT32_TO_STREAM_f (unsigned char *p, unsigned long u32)
{
	*(p)++ = (unsigned char)(u32);
	*(p)++ = (unsigned char)((u32) >> 8);
	*(p)++ = (unsigned char)((u32) >> 16);
	*(p)++ = (unsigned char)((u32) >> 24);
	return p;
}

//*****************************************************************************
//
//!  UINT16_TO_STREAM_f
//!
//!  @param  p       pointer to the new stream
//!  @param  u32     pointer to the 16 bit
//!
//!  @return               pointer to the new stream
//!
//!  @brief               This function is used for copying 16 bit to stream
//!                       while converting to little endian format.
//
//*****************************************************************************

unsigned char* UINT16_TO_STREAM_f (unsigned char *p, unsigned short u16)
{
	*(p)++ = (unsigned char)(u16);
	*(p)++ = (unsigned char)((u16) >> 8);
	return p;
}

//*****************************************************************************
//
//!  STREAM_TO_UINT16_f
//!
//!  @param  p          pointer to the stream
//!  @param  offset     offset in the stream
//!
//!  @return               pointer to the new 16 bit
//!
//!  @brief               This function is used for copying received stream to
//!                       16 bit in little endian format.
//
//*****************************************************************************

unsigned short STREAM_TO_UINT16_f(char* p, unsigned short offset)
{
	unsigned char *cp = (unsigned char*)p;
        return (unsigned short)((unsigned short)((unsigned short)
								(*(cp + offset + 1)) << 8) + (unsigned short)(*(cp + offset)));
}

//*****************************************************************************
//
//!  STREAM_TO_UINT32_f
//!
//!  @param  p          pointer to the stream
//!  @param  offset     offset in the stream
//!
//!  @return               pointer to the new 32 bit
//!
//!  @brief               This function is used for copying received stream to
//!                       32 bit in little endian format.
//
//*****************************************************************************

unsigned long STREAM_TO_UINT32_f(char* p, unsigned short offset)
{
	unsigned char *cp = (unsigned char*)p;
        return (unsigned long)((unsigned long)((unsigned long)
							 (*(cp + offset + 3)) << 24) + (unsigned long)((unsigned long)
							 (*(cp + offset + 2)) << 16) + (unsigned long)((unsigned long)
							 (*(cp + offset + 1)) << 8) + (unsigned long)(*(cp + offset)));
}



//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
