/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void gsm_properties()
{
    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "N900A")) {
        /* hlteatt */
        property_set("ro.build.fingerprint", "samsung/hlteuc/hlteatt:5.0/LRX21V/N900AUCUEOC1:user/morningstar");
        property_set("ro.build.description", "hlteuc-user 5.0 LRX21V N900AUCUEOC1 morningstar");
        property_set("ro.product.model", "SM-N900A");
        property_set("ro.product.name", "hlteuc");
        property_set("ro.product.device", "hlteatt");
    } else if (strstr(bootloader, "N900W8")) {
        /* hltecan */
        if (strstr(bootloader, "N900W8UB")) {
            /* hltecan/ub */
            property_set("ro.build.fingerprint", "samsung/hlteub/hltecan:5.0/LRX21V/N900W8UBU2DOI2:user/morningstar");
            property_set("ro.build.description", "hlteub-user 5.0 LRX21V N900W8UBU2DOI2 morningstar");
            property_set("ro.product.name", "hlteub");
        } else {
            /* hltecan/vl */
            property_set("ro.build.fingerprint", "samsung/hltevl/hltecan:5.0/LRX21V/N900W8VLU2DOH1:user/morningstar");
            property_set("ro.build.description", "hltevl-user 5.0 LRX21V N900W8VLU2DOH1 morningstar");
            property_set("ro.product.name", "hltevl");
        }
        property_set("ro.product.model", "SM-N900W8");
        property_set("ro.product.device", "hltecan");
    } else if (strstr(bootloader, "SC01F")) {
        /* hltedcm */
        property_set("ro.build.fingerprint", "samsung/SC-01F/SC-01F:5.0/LRX21V/SC01FOMUGOI4:user/morningstar");
        property_set("ro.build.description", "hltedcm-user 5.0 LRX21V SC01FOMUGOI4 morningstar");
        property_set("ro.product.model", "SC-01F");
        property_set("ro.product.name", "hltedcm");
        property_set("ro.product.device", "hltedcm");
    } else if (strstr(bootloader, "SCL22")) {
        /* hltekdi */
        property_set("ro.build.fingerprint", "KDDI/SCL22/SCL22:5.0/LRX21V/SCL22KDU2GOH7:user/morningstar");
        property_set("ro.build.description", "hltekdi-user 5.0 LRX21V SCL22KDU2GOH7 morningstar");
        property_set("ro.product.model", "SCL22");
        property_set("ro.product.name", "hltekdi");
        property_set("ro.product.device", "hltekdi");
    } else if (strstr(bootloader, "N900K")) {
        /* hltektt */
        property_set("ro.build.fingerprint", "samsung/hltektt/hltektt:5.0/LRX21V/N900KKKU0GOF2:user/morningstar");
        property_set("ro.build.description", "hltektt-user 5.0 LRX21V N900KKKU0GOF2 morningstar");
        property_set("ro.product.model", "SM-N900K");
        property_set("ro.product.name", "hltektt");
        property_set("ro.product.device", "hltektt");
        } else if (strstr(bootloader, "N900L")) {
        /* hltelgt */
        property_set("ro.build.fingerprint", "samsung/hltelgt/hltelgt:5.0/LRX21V/N900LKLU0GOJ4:user/morningstar");
        property_set("ro.build.description", "hltelgt-user 5.0 LRX21V N900LKLU0GOJ4 morningstar");
        property_set("ro.product.model", "SM-N900L");
        property_set("ro.product.name", "hltelgt");
        property_set("ro.product.device", "hltelgt");
    } else if (strstr(bootloader, "N900S")) {
        /* hlteskt */
        property_set("ro.build.fingerprint", "samsung/hlteskt/hlteskt:5.0/LRX21V/N900SKSU0GOJ2:user/morningstar");
        property_set("ro.build.description", "hlteskt-user 5.0 LRX21V N900SKSU0GOJ2 morningstar");
        property_set("ro.product.model", "SM-N900S");
        property_set("ro.product.name", "hlteskt");
        property_set("ro.product.device", "hlteskt");
    } else if (strstr(bootloader, "N900P")) {
        /* hltespr */
        property_set("ro.build.fingerprint", "samsung/hltespr/hltespr:5.0/LRX21V/N900PVPUEOH1:user/morningstar");
        property_set("ro.build.description", "hltespr-user 5.0 LRX21V N900PVPUEOH1 morningstar");
        property_set("ro.product.model", "SM-N900V");
        property_set("ro.product.name", "hltespr");
        property_set("ro.product.device", "hltespr");
    } else if (strstr(bootloader, "N900T")) {
        /* hltetmo */
        property_set("ro.build.fingerprint", "samsung/hltetmo/hltetmo:5.0/LRX21V/N900TUVUFOB6:user/morningstar");
        property_set("ro.build.description", "hltetmo-user 5.0 LRX21V N900TUVUFOB6 morningstar");
        property_set("ro.product.model", "SM-N900T");
        property_set("ro.product.name", "hltetmo");
        property_set("ro.product.device", "hltetmo");
    } else if (strstr(bootloader, "N900R4")) {
        /* hlteusc */
        property_set("ro.build.fingerprint", "samsung/hlteusc/hlteusc:5.0/LRX21V/N900R4TYUDOH1:user/morningstar");
        property_set("ro.build.description", "hlteusc-user 5.0 LRX21V N900R4TYUDOH1 morningstar");
        property_set("ro.product.model", "SM-N900R4");
        property_set("ro.product.name", "hlteusc");
        property_set("ro.product.device", "hlteusc");
    } else if (strstr(bootloader, "N900V")) {
        /* hltevzw */
        property_set("ro.build.fingerprint", "Verizon/hltevzw/hltevzw:5.0/LRX21V/N900VVRUEOF1:user/morningstar");
        property_set("ro.build.description", "hltevzw-user 5.0 LRX21V N900VVRUEOF1 morningstar");
        property_set("ro.product.model", "SM-N900V");
        property_set("ro.product.name", "hltevzw");
        property_set("ro.product.device", "hltevzw");
    } else {
        /* hlte */
        if (strstr(bootloader, "N9005DX")) {
            /* hlte/dx */
            property_set("ro.build.fingerprint", "samsung/hltedx/hlte:5.0/LRX21V/N9005DXUGBOK1:user/morningstar");
            property_set("ro.build.description", "hltedx-user 5.0 LRX21V N9005DXUGBOK1 morningstar");
            property_set("ro.product.name", "hltedx");
        } else if (strstr(bootloader, "N9005VJ")) {
            /* hlte/vj */
            property_set("ro.build.fingerprint", "samsung/hltevj/hlte:5.0/LRX21V/N9005VJUGBOI3:user/morningstar");
            property_set("ro.build.description", "hltevj-user 5.0 LRX21V N9005VJUGBOI3 morningstar");
            property_set("ro.product.name", "hltevj");
        } else if (strstr(bootloader, "N9005ZS")) {
            /* hlte/zh */
            property_set("ro.build.fingerprint", "samsung/hltezh/hlte:5.0/LRX21V/N9005ZSUGOI1:user/morningstar");
            property_set("ro.build.description", "hltezh-user 5.0 LRX21V N9005ZSUGOI1 morningstar");
            property_set("ro.product.name", "hltezh");
        } else {
            /* all other variants become hlte/xx */
            property_set("ro.build.fingerprint", "samsung/hltexx/hlte:5.0/LRX21V/N9005XXUGBOK6:user/morningstar");
            property_set("ro.build.description", "hltexx-user 5.0 LRX21V N9005XXUGBOK6 morningstar");
            property_set("ro.product.name", "hltexx");
        }
        property_set("ro.product.model", "SM-N9005");
        property_set("ro.product.device", "hlte");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}