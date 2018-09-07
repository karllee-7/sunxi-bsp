/*
 * drivers/net/wireless/orinoco/hermes_rid.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _HERMES_RID_H
#define _HERMES_RID_H

/*
 * Configuration RIDs
 */
#define HERMES_RID_CNFPORTTYPE			0xFC00
#define HERMES_RID_CNFOWNMACADDR		0xFC01
#define HERMES_RID_CNFDESIREDSSID		0xFC02
#define HERMES_RID_CNFOWNCHANNEL		0xFC03
#define HERMES_RID_CNFOWNSSID			0xFC04
#define HERMES_RID_CNFOWNATIMWINDOW		0xFC05
#define HERMES_RID_CNFSYSTEMSCALE		0xFC06
#define HERMES_RID_CNFMAXDATALEN		0xFC07
#define HERMES_RID_CNFWDSADDRESS		0xFC08
#define HERMES_RID_CNFPMENABLED			0xFC09
#define HERMES_RID_CNFPMEPS			0xFC0A
#define HERMES_RID_CNFMULTICASTRECEIVE		0xFC0B
#define HERMES_RID_CNFMAXSLEEPDURATION		0xFC0C
#define HERMES_RID_CNFPMHOLDOVERDURATION	0xFC0D
#define HERMES_RID_CNFOWNNAME			0xFC0E
#define HERMES_RID_CNFOWNDTIMPERIOD		0xFC10
#define HERMES_RID_CNFWDSADDRESS1		0xFC11
#define HERMES_RID_CNFWDSADDRESS2		0xFC12
#define HERMES_RID_CNFWDSADDRESS3		0xFC13
#define HERMES_RID_CNFWDSADDRESS4		0xFC14
#define HERMES_RID_CNFWDSADDRESS5		0xFC15
#define HERMES_RID_CNFWDSADDRESS6		0xFC16
#define HERMES_RID_CNFMULTICASTPMBUFFERING	0xFC17
#define HERMES_RID_CNFWEPENABLED_AGERE		0xFC20
#define HERMES_RID_CNFAUTHENTICATION_AGERE	0xFC21
#define HERMES_RID_CNFMANDATORYBSSID_SYMBOL	0xFC21
#define HERMES_RID_CNFDROPUNENCRYPTED		0xFC22
#define HERMES_RID_CNFWEPDEFAULTKEYID		0xFC23
#define HERMES_RID_CNFDEFAULTKEY0		0xFC24
#define HERMES_RID_CNFDEFAULTKEY1		0xFC25
#define HERMES_RID_CNFMWOROBUST_AGERE		0xFC25
#define HERMES_RID_CNFDEFAULTKEY2		0xFC26
#define HERMES_RID_CNFDEFAULTKEY3		0xFC27
#define HERMES_RID_CNFWEPFLAGS_INTERSIL		0xFC28
#define HERMES_RID_CNFWEPKEYMAPPINGTABLE	0xFC29
#define HERMES_RID_CNFAUTHENTICATION		0xFC2A
#define HERMES_RID_CNFMAXASSOCSTA		0xFC2B
#define	HERMES_RID_CNFKEYLENGTH_SYMBOL		0xFC2B
#define HERMES_RID_CNFTXCONTROL			0xFC2C
#define HERMES_RID_CNFROAMINGMODE		0xFC2D
#define HERMES_RID_CNFHOSTAUTHENTICATION	0xFC2E
#define HERMES_RID_CNFRCVCRCERROR		0xFC30
#define HERMES_RID_CNFMMLIFE			0xFC31
#define HERMES_RID_CNFALTRETRYCOUNT		0xFC32
#define HERMES_RID_CNFBEACONINT			0xFC33
#define HERMES_RID_CNFAPPCFINFO			0xFC34
#define HERMES_RID_CNFSTAPCFINFO		0xFC35
#define HERMES_RID_CNFPRIORITYQUSAGE		0xFC37
#define HERMES_RID_CNFTIMCTRL			0xFC40
#define HERMES_RID_CNFTHIRTY2TALLY		0xFC42
#define HERMES_RID_CNFENHSECURITY		0xFC43
#define HERMES_RID_CNFGROUPADDRESSES		0xFC80
#define HERMES_RID_CNFCREATEIBSS		0xFC81
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD	0xFC82
#define HERMES_RID_CNFRTSTHRESHOLD		0xFC83
#define HERMES_RID_CNFTXRATECONTROL		0xFC84
#define HERMES_RID_CNFPROMISCUOUSMODE		0xFC85
#define HERMES_RID_CNFBASICRATES_SYMBOL		0xFC8A
#define HERMES_RID_CNFPREAMBLE_SYMBOL		0xFC8C
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD0	0xFC90
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD1	0xFC91
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD2	0xFC92
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD3	0xFC93
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD4	0xFC94
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD5	0xFC95
#define HERMES_RID_CNFFRAGMENTATIONTHRESHOLD6	0xFC96
#define HERMES_RID_CNFRTSTHRESHOLD0		0xFC97
#define HERMES_RID_CNFRTSTHRESHOLD1		0xFC98
#define HERMES_RID_CNFRTSTHRESHOLD2		0xFC99
#define HERMES_RID_CNFRTSTHRESHOLD3		0xFC9A
#define HERMES_RID_CNFRTSTHRESHOLD4		0xFC9B
#define HERMES_RID_CNFRTSTHRESHOLD5		0xFC9C
#define HERMES_RID_CNFRTSTHRESHOLD6		0xFC9D
#define HERMES_RID_CNFHOSTSCAN_SYMBOL		0xFCAB
#define HERMES_RID_CNFSHORTPREAMBLE		0xFCB0
#define HERMES_RID_CNFWEPKEYS_AGERE		0xFCB0
#define HERMES_RID_CNFEXCLUDELONGPREAMBLE	0xFCB1
#define HERMES_RID_CNFTXKEY_AGERE		0xFCB1
#define HERMES_RID_CNFAUTHENTICATIONRSPTO	0xFCB2
#define HERMES_RID_CNFSCANSSID_AGERE		0xFCB2
#define HERMES_RID_CNFBASICRATES		0xFCB3
#define HERMES_RID_CNFSUPPORTEDRATES		0xFCB4
#define HERMES_RID_CNFADDDEFAULTTKIPKEY_AGERE	0xFCB4
#define HERMES_RID_CNFSETWPAAUTHMGMTSUITE_AGERE	0xFCB5
#define HERMES_RID_CNFREMDEFAULTTKIPKEY_AGERE	0xFCB6
#define HERMES_RID_CNFADDMAPPEDTKIPKEY_AGERE	0xFCB7
#define HERMES_RID_CNFREMMAPPEDTKIPKEY_AGERE	0xFCB8
#define HERMES_RID_CNFSETWPACAPABILITIES_AGERE	0xFCB9
#define HERMES_RID_CNFCACHEDPMKADDRESS		0xFCBA
#define HERMES_RID_CNFREMOVEPMKADDRESS		0xFCBB
#define HERMES_RID_CNFSCANCHANNELS2GHZ		0xFCC2
#define HERMES_RID_CNFDISASSOCIATE		0xFCC8
#define HERMES_RID_CNFTICKTIME			0xFCE0
#define HERMES_RID_CNFSCANREQUEST		0xFCE1
#define HERMES_RID_CNFJOINREQUEST		0xFCE2
#define HERMES_RID_CNFAUTHENTICATESTATION	0xFCE3
#define HERMES_RID_CNFCHANNELINFOREQUEST	0xFCE4
#define HERMES_RID_CNFHOSTSCAN			0xFCE5

/*
 * Information RIDs
 */
#define HERMES_RID_MAXLOADTIME			0xFD00
#define HERMES_RID_DOWNLOADBUFFER		0xFD01
#define HERMES_RID_PRIID			0xFD02
#define HERMES_RID_PRISUPRANGE			0xFD03
#define HERMES_RID_CFIACTRANGES			0xFD04
#define HERMES_RID_NICSERNUM			0xFD0A
#define HERMES_RID_NICID			0xFD0B
#define HERMES_RID_MFISUPRANGE			0xFD0C
#define HERMES_RID_CFISUPRANGE			0xFD0D
#define HERMES_RID_CHANNELLIST			0xFD10
#define HERMES_RID_REGULATORYDOMAINS		0xFD11
#define HERMES_RID_TEMPTYPE			0xFD12
#define HERMES_RID_CIS				0xFD13
#define HERMES_RID_STAID			0xFD20
#define HERMES_RID_STASUPRANGE			0xFD21
#define HERMES_RID_MFIACTRANGES			0xFD22
#define HERMES_RID_CFIACTRANGES2		0xFD23
#define HERMES_RID_SECONDARYVERSION_SYMBOL	0xFD24
#define HERMES_RID_PORTSTATUS			0xFD40
#define HERMES_RID_CURRENTSSID			0xFD41
#define HERMES_RID_CURRENTBSSID			0xFD42
#define HERMES_RID_COMMSQUALITY			0xFD43
#define HERMES_RID_CURRENTTXRATE		0xFD44
#define HERMES_RID_CURRENTBEACONINTERVAL	0xFD45
#define HERMES_RID_CURRENTSCALETHRESHOLDS	0xFD46
#define HERMES_RID_PROTOCOLRSPTIME		0xFD47
#define HERMES_RID_SHORTRETRYLIMIT		0xFD48
#define HERMES_RID_LONGRETRYLIMIT		0xFD49
#define HERMES_RID_MAXTRANSMITLIFETIME		0xFD4A
#define HERMES_RID_MAXRECEIVELIFETIME		0xFD4B
#define HERMES_RID_CFPOLLABLE			0xFD4C
#define HERMES_RID_AUTHENTICATIONALGORITHMS	0xFD4D
#define HERMES_RID_PRIVACYOPTIONIMPLEMENTED	0xFD4F
#define HERMES_RID_DBMCOMMSQUALITY_INTERSIL	0xFD51
#define HERMES_RID_CURRENTTXRATE1		0xFD80
#define HERMES_RID_CURRENTTXRATE2		0xFD81
#define HERMES_RID_CURRENTTXRATE3		0xFD82
#define HERMES_RID_CURRENTTXRATE4		0xFD83
#define HERMES_RID_CURRENTTXRATE5		0xFD84
#define HERMES_RID_CURRENTTXRATE6		0xFD85
#define HERMES_RID_OWNMACADDR			0xFD86
#define HERMES_RID_SCANRESULTSTABLE		0xFD88
#define HERMES_RID_CURRENT_COUNTRY_INFO		0xFD89
#define HERMES_RID_CURRENT_WPA_IE		0xFD8A
#define HERMES_RID_CURRENT_TKIP_IV		0xFD8B
#define HERMES_RID_CURRENT_ASSOC_REQ_INFO	0xFD8C
#define HERMES_RID_CURRENT_ASSOC_RESP_INFO	0xFD8D
#define HERMES_RID_TXQUEUEEMPTY			0xFD91
#define HERMES_RID_PHYTYPE			0xFDC0
#define HERMES_RID_CURRENTCHANNEL		0xFDC1
#define HERMES_RID_CURRENTPOWERSTATE		0xFDC2
#define HERMES_RID_CCAMODE			0xFDC3
#define HERMES_RID_SUPPORTEDDATARATES		0xFDC6
#define HERMES_RID_BUILDSEQ			0xFFFE
#define HERMES_RID_FWID				0xFFFF

#endif
