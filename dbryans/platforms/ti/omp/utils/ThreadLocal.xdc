/* --COPYRIGHT--,BSD
 * Copyright (c)  2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*
 *  ======== ThreadLocal.xdc ========
 */

import xdc.runtime.Types;
import xdc.runtime.Error;
import xdc.runtime.Assert;
import ti.sysbios.knl.Task;


/*! 
 * ======== ThreadLocal ========
 */
module ThreadLocal
{
    /*!
     *  ======== KeyValueView ========
     *  @_nodoc
     */
    metaonly struct KeyValueView {
        UInt        key;
        UArg        value;
    };

    /*!
     *  ======== rovViewInfo ========
     *  @_nodoc
     */
    @Facet
    metaonly config xdc.rov.ViewInfo.Instance rovViewInfo =
        xdc.rov.ViewInfo.create({
            viewMap: [
                ['Thread local data',
                    {
                        type: xdc.rov.ViewInfo.MODULE_DATA,
                        viewInitFxn: 'viewKeyValues',
                        structName: 'KeyValueView'
                    }
                ]
            ]
        });

    config Assert.Id A_invalidKey = {
        msg: "A_invalidKey: Invalid key encountered"
    };
    
    
    config Assert.Id A_invalidContext = {
        msg: "A_invalidContext: Must be called from Task context"
    };

    /*!
     *  ======== Key ========
     */
    typedef UInt Key;
    
    /*!
     *  ======== DestructFxn ========
     */
    typedef Void (*DestructFxn)(Void *);

    /*!
     *  ======== key_create ========
     */
    @DirectCall 
    Int key_create(Key *keyPtr, DestructFxn destructor);
    
    /*!
     *  ======== key_delete ========
     */
    @DirectCall 
    Int key_delete(Key key);
    
    /*!
     *  ======== setspecific ========
     */
    @DirectCall 
    Int setspecific(Key key, const void *val);
    
    /*!
     *  ======== getspecific ========
     */
    @DirectCall 
    Void *getspecific(Key key);
    
    /*!
     *  ======== createFxn ========
     */
    Void createFxn(Task.Handle tsk, Error.Block *eb);
    
    /*!
     *  ======== exitFxn ========
     */
    Void exitFxn(Task.Handle tsk);
    
    /*!
     *  ======== registerFxn ========
     */
    Void registerFxn(Int id);

internal:

    const Int MAXKEYS = 16;

    struct Module_State {
        UInt contextId;
    };
}
