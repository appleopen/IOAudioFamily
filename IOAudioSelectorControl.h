/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _IOKIT_IOAUDIOSELECTORCONTROL_H
#define _IOKIT_IOAUDIOSELECTORCONTROL_H

#include <IOKit/audio/IOAudioControl.h>

class OSString;
class OSArray;

class IOAudioSelectorControl : public IOAudioControl
{
    OSDeclareDefaultStructors(IOAudioSelectorControl)
    
protected:

    OSArray *availableSelections;

protected:
    struct ExpansionData { };
    
    ExpansionData *reserved;

public:
	static IOAudioSelectorControl *createOutputSelector(SInt32 initialValue,
															UInt32 channelID,
															const char *channelName = 0,
															UInt32 cntrlID = 0);

	virtual IOReturn removeAvailableSelection(SInt32 selectionValue);
	virtual IOReturn replaceAvailableSelection(SInt32 selectionValue, const char *selectionDescription);
	virtual IOReturn replaceAvailableSelection(SInt32 selectionValue, OSString *selectionDescription);

private:
    OSMetaClassDeclareReservedUsed(IOAudioSelectorControl, 0);
    OSMetaClassDeclareReservedUsed(IOAudioSelectorControl, 1);
    OSMetaClassDeclareReservedUsed(IOAudioSelectorControl, 2);

    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 3);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 4);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 5);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 6);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 7);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 8);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 9);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 10);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 11);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 12);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 13);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 14);
    OSMetaClassDeclareReservedUnused(IOAudioSelectorControl, 15);

public:
    static IOAudioSelectorControl *create(SInt32 initialValue,
                                            UInt32 channelID,
                                            const char *channelName = 0,
                                            UInt32 cntrlID = 0,
                                            UInt32 subType = 0,
                                            UInt32 usage = 0);
                                            
    static IOAudioSelectorControl *createInputSelector(SInt32 initialValue,
                                                        UInt32 channelID,
                                                        const char *channelName = 0,
                                                        UInt32 cntrlID = 0);
                                                        
    virtual bool init(SInt32 initialValue,
                      UInt32 channelID,
                      const char *channelName = 0,
                      UInt32 cntrlID = 0,
                      UInt32 subType = 0,
                      UInt32 usage = 0,
                      OSDictionary *properties = 0);

    virtual void free();

    virtual IOReturn addAvailableSelection(SInt32 selectionValue, const char *selectionDescription);
    virtual IOReturn addAvailableSelection(SInt32 selectionValue, OSString *selectionDescription);

    virtual bool valueExists(SInt32 selectorValue);

    virtual IOReturn validateValue(OSObject *newValue);

};

#endif /* _IOKIT_IOAUDIOSELECTORCONTROL_H */
