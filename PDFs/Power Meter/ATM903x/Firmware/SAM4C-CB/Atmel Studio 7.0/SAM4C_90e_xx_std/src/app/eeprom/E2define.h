//===================================================================
//Copyright	idt, all rights is reserved
//mcu type	::	arm 
//fuction	::	electric power research institute signal smart meter
//created	::	zhongtz
//created date :: 2012-04-07 19:14
//===================================================================
#ifndef		_E2define_h
#define		_E2define_h

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


//-------------------------------------------------------------------
//#define		RdE2_DeviceAddr		0xA1		//read eeprom device address
//#define		WrE2_DeviceAddr		0xA0		//write eeprom device address

//------------------------------ page 0 -----------------------------
#define		RdE2Page0Addr		0x00		//page address
#define		WrE2Page0Addr		0x00

#define		E2CurDemandPgAdr		0x00
#define		E2CurEnergyPgAdr		0x00
#define		E2FreezePgAdr			0x00
#define		E2TouPgAdr				0x00

//68		0x00
#define		E2Tou1EnergyAdr			0x01
#define		E2Tou2EnergyAdr			0x09
//68		0x0D
//cs		0x0e
#define		E2Tou3EnergyAdr			0x11
#define		E2Tou4EnergyAdr			0x19
//68		0x1D
//cs		0x1e
#define		E2Tou1Adr		0x20
#define		E2Tou2Adr		0x23
#define		E2Tou3Adr		0x26
#define		E2Tou4Adr		0x29
//cs		0x2e
#define		E2Tou5Adr		0x30
#define		E2Tou6Adr		0x33
#define		E2Tou7Adr		0x36
#define		E2Tou8Adr		0x39
//cs		0x3e
#define		E2TotalMaxDemandAdr		0x40
#define		E2TotalMaxDemandTMAdr	0x44
//EMPTY
//cs		0x4e
#define		E2Tou1MaxDemandAdr		0x50
#define		E2Tou1MaxDemandTMAdr	0x54
//cs		0x5e
#define		E2Tou2MaxDemandAdr		0x60
#define		E2Tou2MaxDemandTMAdr	0x64
//cs		0x6e
#define		E2Tou3MaxDemandAdr		0x70
#define		E2Tou3MaxDemandTMAdr	0x74
//cs		0x7e
#define		E2Tou4MaxDemandAdr		0x80
#define		E2Tou4MaxDemandTMAdr	0x84
//cs		0x8e
#define		E2MeterIDAdr			0x90
//cs		0x9e
#define		E2FreezeDateAdr			0xa0
#define		E2DisplayOnOffAdr		0xA2		
//0xA7 EMPTY
//cs		0xae

//------------------------page 1 bak 1-------------------------------
#define		RdE2Page1Addr		0x01
#define		WrE2Page1Addr		0x01
//------------------------page 2 bak 2-------------------------------
#define		RdE2Page2Addr		0x02
#define		WrE2Page2Addr		0x02

//---------------------------page 3 ---------------------------------
#define		RdE2Page3Addr		0x03
#define		WrE2Page3Addr		0x03

//--------dsp_config-----------------------------
#define		E2_DSP_CFG_control_Adr			0x00
#define		E2_DSP_CFG_service_type_Adr		0x04
#define		E2_DSP_CFG_m_Adr				0x08
//cs		0x0e
#define		E2_DSP_CFG_n_max_Adr				0x10
#define		E2_DSP_CFG_synch_Adr				0x14
#define		E2_DSP_CFG_pulse_control1_Adr		0x18
//cs		0x2e
#define		E2_DSP_CFG_pulse_control2_Adr		0x20
#define		E2_DSP_CFG_pulse_control3_Adr		0x24
#define		E2_DSP_CFG_k_t_Adr					0x28
//cs		0x2e
#define		E2_DSP_CFG_k_width_Adr				0x30
#define		E2_DSP_CFG_creep_control_Adr		0x34
#define		E2_DSP_CFG_creep_threshold_Adr		0x38
//cs		0x3e
#define		E2_DSP_CFG_sensor_type_Adr			0x40
#define		E2_DSP_CFG_k_ia_Adr					0x44
#define		E2_DSP_CFG_k_va_Adr					0x48
//cs		0x4e
#define		E2_DSP_CFG_k_ib_Adr					0x50
#define		E2_DSP_CFG_k_vb_Adr					0x54
#define		E2_DSP_CFG_k_ic_Adr					0x58
//cs		0x5e
#define		E2_DSP_CFG_k_vc_Adr					0x60
#define		E2_DSP_CFG_k_in_Adr					0x64
#define		E2_DSP_CFG_cal_m_ia_Adr				0x68
//cs		0x6e
#define		E2_DSP_CFG_cal_m_va_Adr				0x70
#define		E2_DSP_CFG_cal_m_ib_Adr				0x74
#define		E2_DSP_CFG_cal_m_vb_Adr				0x78
//cs		0x7e
#define		E2_DSP_CFG_cal_m_ic_Adr				0x80
#define		E2_DSP_CFG_cal_m_vc_Adr				0x84
#define		E2_DSP_CFG_cal_m_in_Adr				0x88
//cs		0x8e
#define		E2_DSP_CFG_cal_ph_ia_Adr			0x90
#define		E2_DSP_CFG_cal_ph_va_Adr			0x94
#define		E2_DSP_CFG_cal_ph_ib_Adr			0x98
//cs		0x9e
#define		E2_DSP_CFG_cal_ph_vb_Adr			0xa0
#define		E2_DSP_CFG_cal_ph_ic_Adr			0xa4
#define		E2_DSP_CFG_cal_ph_vc_Adr			0xa8
//cs		0xae
#define		E2_DSP_CFG_cal_ph_in_Adr			0xb0
#define		E2_DSP_CFG_cal_ph_vs_Adr			0xb4
#define		E2_DSP_CFG_va_lim_swell_Adr			0xb8
//cs		0xbe
#define		E2_DSP_CFG_vb_lim_swell_Adr			0xc0
#define		E2_DSP_CFG_vc_lim_swell_Adr			0xc4
#define		E2_DSP_CFG_vs_lim_swell_Adr			0xc8
//cs		0xce
#define		E2_DSP_CFG_va_lim_sag_Adr			0xd0
#define		E2_DSP_CFG_vb_lim_sag_Adr			0xd4
#define		E2_DSP_CFG_vc_lim_sag_Adr			0xd8
//cs		0xde
#define		E2_DSP_CFG_vs_lim_sag_Adr			0xe0
#define		E2_DSP_CFG_atsense_ctrl_20_23_Adr	0xe4
#define		E2_DSP_CFG_atsense_ctrl_24_27_Adr	0xe8
//cs		0xee
#define		E2_DSP_CFG_atsense_ctrl_28_Adr		0xf0
#define		E2_DSP_CFG_harmonic_m_req_Adr		0xf4
#define		E2_DSP_CFG_capture_control_Adr		0xf8
//cs		0xfe
//------------------------page 4 bak 1-------------------------------
#define		RdE2Page4Addr		0x04
#define		WrE2Page4Addr	0x04

//------------------------page 5 bak 2-------------------------------
#define		RdE2Page5Addr		0x05
#define		WrE2Page5Addr	0x05

//---------------------------page 6 ---------------------------------
#define		RdE2Page6Addr		0x06
#define		WrE2Page6Addr	0x06

//--------dsp_config-----------------------------
#define		E2_DSP_CFG_capture_addr_Adr				0x00
#define		E2_DSP_CFG_acc_buffer_control_Adr		0x04
#define		E2_DSP_CFG_acc_buffer_addr_Adr			0x08
//cs		0x0e

//--------meter_control--------------------------
#define		E2_Meter_Control_va_dur_swell_Adr		0x10
#define		E2_Meter_Control_vb_dur_swell_Adr		0x14
#define		E2_Meter_Control_vc_dur_swell_Adr		0x18
//cs		0x1e
#define		E2_Meter_Control_vs_dur_swell_Adr		0x20
#define		E2_Meter_Control_va_dur_sag_Adr			0x24
#define		E2_Meter_Control_vb_dur_sag_Adr			0x28
//cs		0x2e
#define		E2_Meter_Control_vc_dur_sag_Adr			0x30
#define		E2_Meter_Control_vs_dur_sag_Adr			0x34
#define		E2_Meter_Control_meter_type_Adr			0x38
//cs		0x3e
#define		E2_Meter_Control_frequency_Adr			0x40
#define		E2_Meter_Control_line_voltage_Adr		0x44
#define		E2_Meter_Control_load_class_Adr			0x48
//cs		0x4e
#define		E2_Meter_Control_test_amp_Adr			0x50
#define		E2_Meter_Control_n_elements_Adr			0x54
#define		E2_Meter_Control_kt_Adr					0x58
//cs		0x5e
#define		E2_Meter_Control_alert_Adr				0x60
#define		E2_CalibrationStart_Adr					0x64
//#define					0x68
//cs		0x6e

//------------meter calibration------------------
#define		E2_Meter_Cal_cal_m_ia_Adr		0x70
#define		E2_Meter_Cal_cal_m_va_Adr		0x74
#define		E2_Meter_Cal_cal_m_ib_Adr		0x78
//cs		0x7e
#define		E2_Meter_Cal_cal_m_vb_Adr		0x80
#define		E2_Meter_Cal_cal_m_ic_Adr		0x84
#define		E2_Meter_Cal_cal_m_vc_Adr		0x88
//cs		0x8e
#define		E2_Meter_Cal_cal_m_in_Adr		0x90
#define		E2_Meter_Cal_cal_ph_ia_Adr		0x94
#define		E2_Meter_Cal_cal_ph_va_Adr		0x98
//cs		0x9e
#define		E2_Meter_Cal_cal_ph_ib_Adr		0xa0
#define		E2_Meter_Cal_cal_ph_vb_Adr		0xa4
#define		E2_Meter_Cal_cal_ph_ic_Adr		0xa8
//cs		0xae
#define		E2_Meter_Cal_cal_ph_vc_Adr		0xb0
#define		E2_Meter_Cal_cal_ph_in_Adr		0xb4
#define		E2_Meter_Cal_cal_ph_vs_Adr		0xb8
//cs		0xbe

//------------------------page 7 bak 1-------------------------------
#define		RdE2Page7Addr		0x07
#define		WrE2Page7Addr	0x07
//------------------------page 8 bak 2-------------------------------
#define		RdE2Page8Addr		0x08
#define		WrE2Page8Addr	0x08

//---------------------------page 9 ---------------------------------
#define		ReadE2Page9Addr		0x09			// 
#define		WriteE2Page9Addr	0x09

//--------AT90E3x calibration registor--------------------------
#define		RW_AT90E3x_E2PgAddr		0x09

#define		E2_AT90E3x_FunEn0		((RW_AT90E3x_E2PgAddr<<8)+0x00)
#define		E2_AT90E3x_FunEn1		((RW_AT90E3x_E2PgAddr<<8)+0x02)
#define		E2_AT90E3x_ZXConf		((RW_AT90E3x_E2PgAddr<<8)+0x04)
#define		E2_AT90E3x_SagTTH		((RW_AT90E3x_E2PgAddr<<8)+0x06)
#define		E2_AT90E3x_PhaseLossTh	((RW_AT90E3x_E2PgAddr<<8)+0x08)
#define		E2_AT90E3x_INWarnTh0	((RW_AT90E3x_E2PgAddr<<8)+0x0A)
#define		E2_AT90E3x_INWarnTh1	((RW_AT90E3x_E2PgAddr<<8)+0x0C)
//cs		0x0e
#define		E2_AT90E3x_THDNUTh		((RW_AT90E3x_E2PgAddr<<8)+0x10)
#define		E2_AT90E3x_THDNITh		((RW_AT90E3x_E2PgAddr<<8)+0x12)
#define		E2_AT90E3x_DMACtrl		((RW_AT90E3x_E2PgAddr<<8)+0x14)
#define		E2_AT90E3x_DetectCtrl	((RW_AT90E3x_E2PgAddr<<8)+0x16)
#define		E2_AT90E3x_DetectThA	((RW_AT90E3x_E2PgAddr<<8)+0x18)
#define		E2_AT90E3x_DetectThB	((RW_AT90E3x_E2PgAddr<<8)+0x1A)
#define		E2_AT90E3x_DetectThC	((RW_AT90E3x_E2PgAddr<<8)+0x1C)
//cs		0x1e
#define		E2_AT90E3x_PMOffsetA	((RW_AT90E3x_E2PgAddr<<8)+0x20)
#define		E2_AT90E3x_PMOffsetB	((RW_AT90E3x_E2PgAddr<<8)+0x22)
#define		E2_AT90E3x_PMOffsetC	((RW_AT90E3x_E2PgAddr<<8)+0x24)
#define		E2_AT90E3x_PMPGA		((RW_AT90E3x_E2PgAddr<<8)+0x26)
#define		E2_AT90E3x_PMconfig		((RW_AT90E3x_E2PgAddr<<8)+0x28)
#define		E2_AT90E3x_PMAvgSamples	((RW_AT90E3x_E2PgAddr<<8)+0x2A)
#define		E2_AT90E3x_ConfigStart	((RW_AT90E3x_E2PgAddr<<8)+0x2C)
//cs		0x2e
#define		E2_AT90E3x_PLConstH		((RW_AT90E3x_E2PgAddr<<8)+0x30)
#define		E2_AT90E3x_PLConstL		((RW_AT90E3x_E2PgAddr<<8)+0x32)
#define		E2_AT90E3x_MMode0		((RW_AT90E3x_E2PgAddr<<8)+0x34)
#define		E2_AT90E3x_MMode1		((RW_AT90E3x_E2PgAddr<<8)+0x36)
#define		E2_AT90E3x_PStartTh		((RW_AT90E3x_E2PgAddr<<8)+0x38)
#define		E2_AT90E3x_QStartTh		((RW_AT90E3x_E2PgAddr<<8)+0x3A)
#define		E2_AT90E3x_SStartTh		((RW_AT90E3x_E2PgAddr<<8)+0x3C)
//cs		0x3e
#define		E2_AT90E3x_PPhaseTh		((RW_AT90E3x_E2PgAddr<<8)+0x40)
#define		E2_AT90E3x_QPhaseTh		((RW_AT90E3x_E2PgAddr<<8)+0x42)
#define		E2_AT90E3x_SPhaseTh		((RW_AT90E3x_E2PgAddr<<8)+0x44)
#define		E2_AT90E3x_CS0			((RW_AT90E3x_E2PgAddr<<8)+0x46)
#define		E2_AT90E3x_CalStart		((RW_AT90E3x_E2PgAddr<<8)+0x48)
#define		E2_AT90E3x_POffsetA		((RW_AT90E3x_E2PgAddr<<8)+0x4A)
#define		E2_AT90E3x_QOffsetA		((RW_AT90E3x_E2PgAddr<<8)+0x4C)
//cs		0x4e
#define		E2_AT90E3x_POffsetB		((RW_AT90E3x_E2PgAddr<<8)+0x50)
#define		E2_AT90E3x_QOffsetB		((RW_AT90E3x_E2PgAddr<<8)+0x52)
#define		E2_AT90E3x_POffsetC		((RW_AT90E3x_E2PgAddr<<8)+0x54)
#define		E2_AT90E3x_QOffsetC		((RW_AT90E3x_E2PgAddr<<8)+0x56)
#define		E2_AT90E3x_PQGainA		((RW_AT90E3x_E2PgAddr<<8)+0x58)
#define		E2_AT90E3x_PhiA			((RW_AT90E3x_E2PgAddr<<8)+0x5A)
#define		E2_AT90E3x_PQGainB		((RW_AT90E3x_E2PgAddr<<8)+0x5C)
//cs		0x5e
#define		E2_AT90E3x_PhiB			((RW_AT90E3x_E2PgAddr<<8)+0x60)
#define		E2_AT90E3x_PQGainC		((RW_AT90E3x_E2PgAddr<<8)+0x62)
#define		E2_AT90E3x_PhiC			((RW_AT90E3x_E2PgAddr<<8)+0x64)
#define		E2_AT90E3x_CS1			((RW_AT90E3x_E2PgAddr<<8)+0x66)
#define		E2_AT90E3x_HarmStart	((RW_AT90E3x_E2PgAddr<<8)+0x68)
#define		E2_AT90E3x_POffsetAF	((RW_AT90E3x_E2PgAddr<<8)+0x6A)
#define		E2_AT90E3x_POffsetBF	((RW_AT90E3x_E2PgAddr<<8)+0x6C)
//cs		0x6e
#define		E2_AT90E3x_POffsetCF	((RW_AT90E3x_E2PgAddr<<8)+0x70)
#define		E2_AT90E3x_PGainAF		((RW_AT90E3x_E2PgAddr<<8)+0x72)
#define		E2_AT90E3x_PGainBF		((RW_AT90E3x_E2PgAddr<<8)+0x74)
#define		E2_AT90E3x_PGainCF		((RW_AT90E3x_E2PgAddr<<8)+0x76)
#define		E2_AT90E3x_CS2			((RW_AT90E3x_E2PgAddr<<8)+0x78)
#define		E2_AT90E3x_AdjStart		((RW_AT90E3x_E2PgAddr<<8)+0x7A)
#define		E2_AT90E3x_UGainA		((RW_AT90E3x_E2PgAddr<<8)+0x7C)
//cs		0x7e
#define		E2_AT90E3x_IGainA		((RW_AT90E3x_E2PgAddr<<8)+0x80)
#define		E2_AT90E3x_UOffsetA		((RW_AT90E3x_E2PgAddr<<8)+0x82)
#define		E2_AT90E3x_IOffsetA		((RW_AT90E3x_E2PgAddr<<8)+0x84)
#define		E2_AT90E3x_UGainB		((RW_AT90E3x_E2PgAddr<<8)+0x86)
#define		E2_AT90E3x_IGainB		((RW_AT90E3x_E2PgAddr<<8)+0x88)
#define		E2_AT90E3x_UOffsetB		((RW_AT90E3x_E2PgAddr<<8)+0x8A)
#define		E2_AT90E3x_IOffsetB		((RW_AT90E3x_E2PgAddr<<8)+0x8C)
//cs		0x8e
#define		E2_AT90E3x_UGainC		((RW_AT90E3x_E2PgAddr<<8)+0x90)
#define		E2_AT90E3x_IGainC		((RW_AT90E3x_E2PgAddr<<8)+0x92)
#define		E2_AT90E3x_UOffsetC		((RW_AT90E3x_E2PgAddr<<8)+0x94)
#define		E2_AT90E3x_IOffsetC		((RW_AT90E3x_E2PgAddr<<8)+0x96)
#define		E2_AT90E3x_IGainN		((RW_AT90E3x_E2PgAddr<<8)+0x98)
#define		E2_AT90E3x_IOffsetN		((RW_AT90E3x_E2PgAddr<<8)+0x9A)
#define		E2_AT90E3x_CS3			((RW_AT90E3x_E2PgAddr<<8)+0x9C)
//cs		0x9e
#define		E2_AT90E3x_BGCurveK		((RW_AT90E3x_E2PgAddr<<8)+0xA0)
#define		E2_AT90E3x_PMIGainA		((RW_AT90E3x_E2PgAddr<<8)+0xA2)
#define		E2_AT90E3x_PMIGainB		((RW_AT90E3x_E2PgAddr<<8)+0xA4)
#define		E2_AT90E3x_PMIGainC		((RW_AT90E3x_E2PgAddr<<8)+0xA6)
#define		E2_AT90E3x_BG_Temp_P12	((RW_AT90E3x_E2PgAddr<<8)+0xA8)
#define		E2_AT90E3x_BG_Temp_P34	((RW_AT90E3x_E2PgAddr<<8)+0xAA)
#define		E2_AT90E3x_BG_Temp_P56	((RW_AT90E3x_E2PgAddr<<8)+0xAC)
//cs		0xAE
#define		E2_AT90E3x_BG_Temp_P78	((RW_AT90E3x_E2PgAddr<<8)+0xB0)
#define		E2_AT90E3x_BG_Temp_N12	((RW_AT90E3x_E2PgAddr<<8)+0xB2)
#define		E2_AT90E3x_BG_Temp_N34	((RW_AT90E3x_E2PgAddr<<8)+0xB4)
#define		E2_AT90E3x_BG_Temp_N56	((RW_AT90E3x_E2PgAddr<<8)+0xB6)
#define		E2_AT90E3x_BG_Temp_N78	((RW_AT90E3x_E2PgAddr<<8)+0xB8)

#define		E2_AT90E32_TempCompGain	((RW_AT90E3x_E2PgAddr<<8)+0xBA)
#define		E2_AT90E32_TempCompRef	((RW_AT90E3x_E2PgAddr<<8)+0xBC)
//cs		0xBE

#define		E2_AT90E3x_UIScal		((RW_AT90E3x_E2PgAddr<<8)+0xC0)
//cs		0xCE
//------------------------page 10 bak 1-------------------------------
#define		RdE2Page10Addr	0x0A
#define		WrE2Page10Addr	0x0A
//------------------------page 11 bak 2-------------------------------
#define		RdE2Page11Addr	0x0B
#define		WrE2Page11Addr	0x0B

//---------------------------page 12 --------------------------------
#define		RdE2Page12Addr	0x0C
#define		WrE2Page12Addr	0x0C

//--------AT90E25 calibration registor--------------------------
#define		RW90E2x_E2PgAddr	0x0C

#define		E2_AT90E2x_FunEn			((RW90E2x_E2PgAddr<<8)+0x00)
#define		E2_AT90E2x_SagTTH			((RW90E2x_E2PgAddr<<8)+0x02)
#define		E2_AT90E2x_SmallPMod		((RW90E2x_E2PgAddr<<8)+0x04)
#define		E2_AT90E2x_CalStart			((RW90E2x_E2PgAddr<<8)+0x06)
#define		E2_AT90E2x_PLConstH			((RW90E2x_E2PgAddr<<8)+0x08)
#define		E2_AT90E2x_PLConstL			((RW90E2x_E2PgAddr<<8)+0x0A)
#define		E2_AT90E2x_LGain			((RW90E2x_E2PgAddr<<8)+0x0C)
//cs		0x0e
#define		E2_AT90E2x_LPhi				((RW90E2x_E2PgAddr<<8)+0x10)
#define		E2_AT90E2x_NGain			((RW90E2x_E2PgAddr<<8)+0x12)
#define		E2_AT90E2x_NPhi				((RW90E2x_E2PgAddr<<8)+0x14)
#define		E2_AT90E2x_PStartTH			((RW90E2x_E2PgAddr<<8)+0x16)
#define		E2_AT90E2x_PNolTH			((RW90E2x_E2PgAddr<<8)+0x18)
#define		E2_AT90E2x_QStartTH			((RW90E2x_E2PgAddr<<8)+0x1A)
#define		E2_AT90E2x_QNolTH			((RW90E2x_E2PgAddr<<8)+0x1C)
//cs		0x1e
#define		E2_AT90E2x_MMode			((RW90E2x_E2PgAddr<<8)+0x20)
#define		E2_AT90E2x_CS1				((RW90E2x_E2PgAddr<<8)+0x22)
#define		E2_AT90E2x_AdjStart			((RW90E2x_E2PgAddr<<8)+0x24)
#define		E2_AT90E2x_Ugain			((RW90E2x_E2PgAddr<<8)+0x26)
#define		E2_AT90E2x_IgainL			((RW90E2x_E2PgAddr<<8)+0x28)
#define		E2_AT90E2x_IgainN			((RW90E2x_E2PgAddr<<8)+0x2A)
#define		E2_AT90E2x_Uoffset			((RW90E2x_E2PgAddr<<8)+0x2C)
//cs		0x2e
#define		E2_AT90E2x_IoffsetL			((RW90E2x_E2PgAddr<<8)+0x30)
#define		E2_AT90E2x_IoffsetN			((RW90E2x_E2PgAddr<<8)+0x32)
#define		E2_AT90E2x_PoffsetL			((RW90E2x_E2PgAddr<<8)+0x34)
#define		E2_AT90E2x_PoffsetN			((RW90E2x_E2PgAddr<<8)+0x36)
#define		E2_AT90E2x_QoffsetL			((RW90E2x_E2PgAddr<<8)+0x38)
#define		E2_AT90E2x_QoffsetN			((RW90E2x_E2PgAddr<<8)+0x3A)
#define		E2_AT90E2x_CS2				((RW90E2x_E2PgAddr<<8)+0x3C)
//cs		0x3e
#define		E2_AT90E2x_UIScal			((RW90E2x_E2PgAddr<<8)+0x40)
//cs		0x4e


//------------------------page 13 bak 1-------------------------------
#define		ReadE2Page13Addr	0x0D
#define		WriteE2Page13Addr	0x0D

//------------------------page 14 bak 2-------------------------------
#define		ReadE2Page14Addr	0x0E
#define		WriteE2Page14Addr	0x0E

//---------------------------page 15 --------------------------------
#define		RdE2Page15Addr	0x0F
#define		WrE2Page15Addr	0x0F

//--------AT90E3x calibration registor--------------------------
#define		RW_D0_AT90E3x_E2PgAddr		0x0F
#define		E2_AT90E3x_000_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x00)
#define		E2_AT90E3x_001_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x02)
#define		E2_AT90E3x_002_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x04)
#define		E2_AT90E3x_003_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x06)
#define		E2_AT90E3x_004_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x08)
#define		E2_AT90E3x_005_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x0A)
#define		E2_AT90E3x_006_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x0C)
#define		E2_AT90E3x_007_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x0E)
#define		E2_AT90E3x_008_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x10)
#define		E2_AT90E3x_009_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x12)
#define		E2_AT90E3x_00A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x14)
#define		E2_AT90E3x_00B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x16)
#define		E2_AT90E3x_00C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x18)
#define		E2_AT90E3x_00D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x1A)
#define		E2_AT90E3x_00E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x1C)
#define		E2_AT90E3x_00F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x1E)

#define		E2_AT90E3x_010_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x20)
#define		E2_AT90E3x_011_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x22)
#define		E2_AT90E3x_012_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x24)
#define		E2_AT90E3x_013_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x26)
#define		E2_AT90E3x_014_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x28)
#define		E2_AT90E3x_015_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x2A)
#define		E2_AT90E3x_016_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x2C)
#define		E2_AT90E3x_017_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x2E)
#define		E2_AT90E3x_018_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x30)
#define		E2_AT90E3x_019_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x32)
#define		E2_AT90E3x_01A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x34)
#define		E2_AT90E3x_01B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x36)
#define		E2_AT90E3x_01C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x38)
#define		E2_AT90E3x_01D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x3A)
#define		E2_AT90E3x_01E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x3C)
#define		E2_AT90E3x_01F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x3E)

#define		E2_AT90E3x_020_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x40)
#define		E2_AT90E3x_021_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x42)
#define		E2_AT90E3x_022_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x44)
#define		E2_AT90E3x_023_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x46)
#define		E2_AT90E3x_024_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x48)
#define		E2_AT90E3x_025_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x4A)
#define		E2_AT90E3x_026_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x4C)
#define		E2_AT90E3x_027_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x4E)
#define		E2_AT90E3x_028_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x50)
#define		E2_AT90E3x_029_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x52)
#define		E2_AT90E3x_02A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x54)
#define		E2_AT90E3x_02B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x56)
#define		E2_AT90E3x_02C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x58)
#define		E2_AT90E3x_02D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x5A)
#define		E2_AT90E3x_02E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x5C)
#define		E2_AT90E3x_02F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x5E)

#define		E2_AT90E3x_030_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x60)
#define		E2_AT90E3x_031_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x62)
#define		E2_AT90E3x_032_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x64)
#define		E2_AT90E3x_033_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x66)
#define		E2_AT90E3x_034_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x68)
#define		E2_AT90E3x_035_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x6A)
#define		E2_AT90E3x_036_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x6C)
#define		E2_AT90E3x_037_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x6E)
#define		E2_AT90E3x_038_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x70)
#define		E2_AT90E3x_039_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x72)
#define		E2_AT90E3x_03A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x74)
#define		E2_AT90E3x_03B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x76)
#define		E2_AT90E3x_03C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x78)
#define		E2_AT90E3x_03D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x7A)
#define		E2_AT90E3x_03E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x7C)
#define		E2_AT90E3x_03F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x7E)

#define		E2_AT90E3x_040_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x80)
#define		E2_AT90E3x_041_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x82)
#define		E2_AT90E3x_042_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x84)
#define		E2_AT90E3x_043_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x86)
#define		E2_AT90E3x_044_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x88)
#define		E2_AT90E3x_045_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x8A)
#define		E2_AT90E3x_046_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x8C)
#define		E2_AT90E3x_047_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x8E)
#define		E2_AT90E3x_048_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x90)
#define		E2_AT90E3x_049_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x92)
#define		E2_AT90E3x_04A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x94)
#define		E2_AT90E3x_04B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x96)
#define		E2_AT90E3x_04C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x98)
#define		E2_AT90E3x_04D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x9A)
#define		E2_AT90E3x_04E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x9C)
#define		E2_AT90E3x_04F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0x9E)

#define		E2_AT90E3x_050_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xA0)
#define		E2_AT90E3x_051_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xA2)
#define		E2_AT90E3x_052_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xA4)
#define		E2_AT90E3x_053_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xA6)
#define		E2_AT90E3x_054_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xA8)
#define		E2_AT90E3x_055_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xAA)
#define		E2_AT90E3x_056_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xAC)
#define		E2_AT90E3x_057_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xAE)
#define		E2_AT90E3x_058_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xB0)
#define		E2_AT90E3x_059_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xB2)
#define		E2_AT90E3x_05A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xB4)
#define		E2_AT90E3x_05B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xB6)
#define		E2_AT90E3x_05C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xB8)
#define		E2_AT90E3x_05D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xBA)
#define		E2_AT90E3x_05E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xBC)
#define		E2_AT90E3x_05F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xBE)

#define		E2_AT90E3x_060_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xC0)
#define		E2_AT90E3x_061_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xC2)
#define		E2_AT90E3x_062_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xC4)
#define		E2_AT90E3x_063_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xC6)
#define		E2_AT90E3x_064_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xC8)
#define		E2_AT90E3x_065_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xCA)
#define		E2_AT90E3x_066_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xCC)
#define		E2_AT90E3x_067_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xCE)
#define		E2_AT90E3x_068_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xD0)
#define		E2_AT90E3x_069_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xD2)
#define		E2_AT90E3x_06A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xD4)
#define		E2_AT90E3x_06B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xD6)
#define		E2_AT90E3x_06C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xD8)
#define		E2_AT90E3x_06D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xDA)
#define		E2_AT90E3x_06E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xDC)
#define		E2_AT90E3x_06F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xDE)

#define		E2_AT90E3x_070_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xE0)
#define		E2_AT90E3x_071_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xE2)
#define		E2_AT90E3x_072_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xE4)
#define		E2_AT90E3x_073_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xE6)
#define		E2_AT90E3x_074_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xE8)
#define		E2_AT90E3x_075_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xEA)
#define		E2_AT90E3x_076_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xEC)
#define		E2_AT90E3x_077_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xEE)
#define		E2_AT90E3x_078_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xF0)
#define		E2_AT90E3x_079_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xF2)
#define		E2_AT90E3x_07A_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xF4)
#define		E2_AT90E3x_07B_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xF6)
#define		E2_AT90E3x_07C_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xF8)
#define		E2_AT90E3x_07D_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xFA)
#define		E2_AT90E3x_07E_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xFC)
#define		E2_AT90E3x_07F_Register		((RW_D0_AT90E3x_E2PgAddr<<8)+0xFE)

//------------------------page 16 -----------------------------------
#define		ReadE2Page16Addr		0x10
#define		WriteE2Page16Addr		0x10
#define		RW_D8_AT90E3x_E2PgAddr		0x10

#define		E2_AT90E3x_800_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x00)
#define		E2_AT90E3x_801_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x02)
#define		E2_AT90E3x_802_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x04)
#define		E2_AT90E3x_803_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x06)
#define		E2_AT90E3x_804_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x08)
#define		E2_AT90E3x_805_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x0A)
#define		E2_AT90E3x_806_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x0C)
#define		E2_AT90E3x_807_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x0E)
#define		E2_AT90E3x_808_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x10)
#define		E2_AT90E3x_809_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x12)
#define		E2_AT90E3x_80A_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x14)
#define		E2_AT90E3x_80B_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x16)
#define		E2_AT90E3x_80C_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x18)
#define		E2_AT90E3x_80D_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x1A)
#define		E2_AT90E3x_80E_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x1C)
#define		E2_AT90E3x_80F_Register		((RW_D8_AT90E3x_E2PgAddr<<8)+0x1E)


//------------------------page 17 bak 2------------------------------
#define		ReadE2Page17Addr		0x11
#define		WriteE2Page17Addr		0x11

//---------------------------page 18 --------------------------------
#define		ReadE2Page18Addr	0x12
#define		WriteE2Page18Addr	0x12

//---------------------------page 19 --------------------------------
#define		ReadE2Page19Addr	0x13
#define		WriteE2Page19Addr	0x13

//---------------------------page 20 --------------------------------
#define		ReadE2Page20Addr	0x14
#define		WriteE2Page20Addr	0x14

//---------------------------page 21 --------------------------------
#define		ReadE2Page21Addr		0x15
#define		WriteE2Page21Addr		0x15


//---------------------------page 22 --------------------------------
#define		ReadE2Page22Addr		0x16
#define		WriteE2Page22Addr		0x16

#define		RW_EnergyDecPgAdr		0x16	

#define		E2Tou1EnergyDecAddr		0x1600
#define		E2Tou2EnergyDecAddr		0x1610
#define		E2Tou3EnergyDecAddr		0x1620
#define		E2Tou4EnergyDecAddr		0x1630

#define		E2HistorySaveTMAdr		0x1640		//year/month/day/hour
//---------------------------page 23 --------------------------------
#define		ReadE2Page23Addr				0x17
#define		WriteE2Page23Addr				0x17

#define		E2_RW_HistoryEnergyPgAdr	0x17

#define		E2Pre1Tou1EnergyAdr			0x00		//the last history month energy
#define		E2Pre1Tou2EnergyAdr			0x04
#define		E2Pre1Tou3EnergyAdr			0x08
#define		E2Pre1Tou4EnergyAdr			0x0C
#define		E2Pre2Tou1EnergyAdr			0x10
#define		E2Pre2Tou2EnergyAdr			0x14
#define		E2Pre2Tou3EnergyAdr			0x18
#define		E2Pre2Tou4EnergyAdr			0x1C
#define		E2Pre3Tou1EnergyAdr			0x20
#define		E2Pre3Tou2EnergyAdr			0x24
#define		E2Pre3Tou3EnergyAdr			0x28
#define		E2Pre3Tou4EnergyAdr			0x2C
#define		E2Pre4Tou1EnergyAdr			0x30
#define		E2Pre4Tou2EnergyAdr			0x34
#define		E2Pre4Tou3EnergyAdr			0x38
#define		E2Pre4Tou4EnergyAdr			0x3C
#define		E2Pre5Tou1EnergyAdr			0x40
#define		E2Pre5Tou2EnergyAdr			0x44
#define		E2Pre5Tou3EnergyAdr			0x48
#define		E2Pre5Tou4EnergyAdr			0x4C
#define		E2Pre6Tou1EnergyAdr			0x50
#define		E2Pre6Tou2EnergyAdr			0x54
#define		E2Pre6Tou3EnergyAdr			0x58
#define		E2Pre6Tou4EnergyAdr			0x5C
#define		E2Pre7Tou1EnergyAdr			0x60
#define		E2Pre7Tou2EnergyAdr			0x64
#define		E2Pre7Tou3EnergyAdr			0x68
#define		E2Pre7Tou4EnergyAdr			0x6C
#define		E2Pre8Tou1EnergyAdr			0x70
#define		E2Pre8Tou2EnergyAdr			0x74
#define		E2Pre8Tou3EnergyAdr			0x78
#define		E2Pre8Tou4EnergyAdr			0x7C
#define		E2Pre9Tou1EnergyAdr			0x80
#define		E2Pre9Tou2EnergyAdr			0x84
#define		E2Pre9Tou3EnergyAdr			0x88
#define		E2Pre9Tou4EnergyAdr			0x8C
#define		E2Pre10Tou1EnergyAdr		0x90
#define		E2Pre10Tou2EnergyAdr		0x94
#define		E2Pre10Tou3EnergyAdr		0x98
#define		E2Pre10Tou4EnergyAdr		0x9C
#define		E2Pre11Tou1EnergyAdr		0xa0
#define		E2Pre11Tou2EnergyAdr		0xa4
#define		E2Pre11Tou3EnergyAdr		0xa8
#define		E2Pre11Tou4EnergyAdr		0xaC
#define		E2Pre12Tou1EnergyAdr		0xb0
#define		E2Pre12Tou2EnergyAdr		0xb4
#define		E2Pre12Tou3EnergyAdr		0xb8
#define		E2Pre12Tou4EnergyAdr		0xbC

//---------------------------page 24 --------------------------------
#define		ReadE2Page24Addr				0x18
#define		WriteE2Page24Addr				0x18

#define		E2HistroyDemandPgAdr			0x18

#define		E2Pre1TotalMaxDemandAdr			0x00		//the last history month total maxim demand
#define		E2Pre1TotalMaxDemandTMAdr		0x04		//the last history month total maxim demand happend time
#define		E2Pre1Tou1MaxDemandAdr			0x08		//the last history month tou1 maxim demand
#define		E2Pre1Tou1MaxDemandTMAdr		0x0C		//the last history month tou2 maxim demand happend time
#define		E2Pre2TotalMaxDemandAdr			0x10		//
#define		E2Pre2TotalMaxDemandTMAdr		0x14		//
#define		E2Pre2Tou1MaxDemandAdr			0x18		//
#define		E2Pre2Tou1MaxDemandTMAdr		0x1C		//
#define		E2Pre3TotalMaxDemandAdr			0x20		//
#define		E2Pre3TotalMaxDemandTMAdr		0x24		//
#define		E2Pre3Tou1MaxDemandAdr			0x28		//
#define		E2Pre3Tou1MaxDemandTMAdr		0x2C		//
#define		E2Pre4TotalMaxDemandAdr			0x30		//
#define		E2Pre4TotalMaxDemandTMAdr		0x34		//
#define		E2Pre4Tou1MaxDemandAdr			0x38		//
#define		E2Pre4Tou1MaxDemandTMAdr		0x3C		//
#define		E2Pre5TotalMaxDemandAdr			0x40		//
#define		E2Pre5TotalMaxDemandTMAdr		0x44		//
#define		E2Pre5Tou1MaxDemandAdr			0x48		//
#define		E2Pre5Tou1MaxDemandTMAdr		0x4C		//
#define		E2Pre6TotalMaxDemandAdr			0x50		//
#define		E2Pre6TotalMaxDemandTMAdr		0x54		//
#define		E2Pre6Tou1MaxDemandAdr			0x58		//
#define		E2Pre6Tou1MaxDemandTMAdr		0x5C		//
#define		E2Pre7TotalMaxDemandAdr			0x60		//
#define		E2Pre7TotalMaxDemandTMAdr		0x64		//
#define		E2Pre7Tou1MaxDemandAdr			0x68		//
#define		E2Pre7Tou1MaxDemandTMAdr		0x6C		//
#define		E2Pre8TotalMaxDemandAdr			0x70		//
#define		E2Pre8TotalMaxDemandTMAdr		0x74		//
#define		E2Pre8Tou1MaxDemandAdr			0x78		//
#define		E2Pre8Tou1MaxDemandTMAdr		0x7C		//
#define		E2Pre9TotalMaxDemandAdr			0x80		//
#define		E2Pre9TotalMaxDemandTMAdr		0x84		//
#define		E2Pre9Tou1MaxDemandAdr			0x88		//
#define		E2Pre9Tou1MaxDemandTMAdr		0x8C		//
#define		E2Pre10TotalMaxDemandAdr		0x90		//
#define		E2Pre10TotalMaxDemandTMAdr		0x94		//
#define		E2Pre10Tou1MaxDemandAdr			0x98		//
#define		E2Pre10Tou1MaxDemandTMAdr		0x9C		//

#define		E2Pre11TotalMaxDemandAdr		0xA0		//
#define		E2Pre11TotalMaxDemandTMAdr		0xA4		//
#define		E2Pre11Tou1MaxDemandAdr			0xA8		//
#define		E2Pre11Tou1MaxDemandTMAdr		0xAC		//
#define		E2Pre12TotalMaxDemandAdr		0xB0		//
#define		E2Pre12TotalMaxDemandTMAdr		0xB4		//
#define		E2Pre12Tou1MaxDemandAdr			0xB8		//
#define		E2Pre12Tou1MaxDemandTMAdr		0xBC		//

//---------------------------page 25 --------------------------------
#define		ReadE2Page25Addr				0x19
#define		WriteE2Page25Addr				0x19

#define		E2Pre1Tou2MaxDemandAdr			0x00		//the last history month tou1 maxim demand
#define		E2Pre1Tou2MaxDemandTMAdr		0x04		//the last history month tou2 maxim demand happend time
#define		E2Pre1Tou3MaxDemandAdr			0x08		//the last history month tou1 maxim demand
#define		E2Pre1Tou3MaxDemandTMAdr		0x0C		//the last history month tou2 maxim demand happend time


#define		E2Pre11Tou2MaxDemandAdr			0xA0		//
#define		E2Pre11Tou2MaxDemandTMAdr		0xA4		//
#define		E2Pre11Tou3MaxDemandAdr			0xA8		//
#define		E2Pre11Tou3MaxDemandTMAdr		0xAC		//

#define		E2Pre12Tou2MaxDemandAdr			0xB0		//
#define		E2Pre12Tou2MaxDemandTMAdr		0xB4		//
#define		E2Pre12Tou3MaxDemandAdr			0xB8		//
#define		E2Pre12Tou3MaxDemandTMAdr		0xBC		//


//---------------------------page 26 --------------------------------
#define		ReadE2Page26Addr				0x1A
#define		WriteE2Page26Addr				0x1A

#define		E2Pre1Tou4MaxDemandAdr			0x00		//the last history month tou1 maxim demand
#define		E2Pre1Tou4MaxDemandTMAdr		0x04		//the last history month tou2 maxim demand happend time
#define		E2Pre2Tou4MaxDemandAdr			0x08		//
#define		E2Pre2Tou4MaxDemandTMAdr		0x0C		//
#define		E2Pre3Tou4MaxDemandAdr			0x10		//
#define		E2Pre3Tou4MaxDemandTMAdr		0x14		//
#define		E2Pre4Tou4MaxDemandAdr			0x18		//
#define		E2Pre4Tou4MaxDemandTMAdr		0x1C		//
#define		E2Pre5Tou4MaxDemandAdr			0x20		//
#define		E2Pre5Tou4MaxDemandTMAdr		0x24		//
#define		E2Pre6Tou4MaxDemandAdr			0x28		//
#define		E2Pre6Tou4MaxDemandTMAdr		0x2C		//
#define		E2Pre7Tou4MaxDemandAdr			0x30		//
#define		E2Pre7Tou4MaxDemandTMAdr		0x34		//
#define		E2Pre8Tou4MaxDemandAdr			0x38		//
#define		E2Pre8Tou4MaxDemandTMAdr		0x3C		//
#define		E2Pre9Tou4MaxDemandAdr			0x40		//
#define		E2Pre9Tou4MaxDemandTMAdr		0x44		//
#define		E2Pre10Tou4MaxDemandAdr			0x48		//
#define		E2Pre10Tou4MaxDemandTMAdr		0x4C		//
#define		E2Pre11Tou4MaxDemandAdr			0x50		//
#define		E2Pre11Tou4MaxDemandTMAdr		0x54		//
#define		E2Pre12Tou4MaxDemandAdr			0x58		//
#define		E2Pre12Tou4MaxDemandTMAdr		0x5C		//


//---------------------------page 27--------------------------------------
#define		ReadE2Page27Addr				0x1B
#define		WriteE2Page27Addr				0x1B

//---------------------------page 28--------------------------------------
#define		ReadE2Page28Addr				0x1C
#define		WriteE2Page28Addr				0x1C
//---------------------------page 29 --------------------------------
//energy clear event//
#define		ReadE2Page29Addr				0x1D
#define		WriteE2Page29Addr				0x1D

//---------------------------page 30 --------------------------------
//event clear event//
#define		ReadE2Page30Addr				0x1E
#define		WriteE2Page30Addr				0x1E


//---------------------------page 31 --------------------------------
//broadcast event//
#define		ReadE2Page31Addr				0x1F
#define		WriteE2Page31Addr				0x1F

//---------------------------page 32 --------------------------------
#define		ReadE2Page32Addr				0x20    
#define		WriteE2Page32Addr				0x20

//---------------------------page 33 --------------------------------
#define		ReadE2Page33Addr				0x21
#define		WriteE2Page33Addr				0x21

//---------------------------page 34 --------------------------------
#define		ReadE2Page34Addr				0x22
#define		WriteE2Page34Addr				0x22


//---------------------------page 35 --------------------------------
#define		ReadE2Page35Addr				0x23
#define		WriteE2Page35Addr				0x23

//---------------------------page 36 --------------------------------
#define		ReadE2Page36Addr				0x24
#define		WriteE2Page36Addr				0x24

//---------------------------page 37 --------------------------------
#define		ReadE2Page37Addr				0x25
#define		WriteE2Page37Addr				0x25

//---------------------------page 38 --------------------------------
#define		ReadE2Page38Addr				0x26
#define		WriteE2Page38Addr				0x26

//---------------------------page 39 --------------------------------
#define		ReadE2Page39Addr				0x27
#define		WriteE2Page39Addr				0x27

//---------------------------page 40 --------------------------------
#define		ReadE2Page40Addr				0x28        //instant and ladder freeze data
#define		WriteE2Page40Addr				0x28

//---------------------------page 41 --------------------------------
#define		ReadE2Page41Addr				0x29        //1 to 5 num time freeze data
#define		WriteE2Page41Addr				0x29

//---------------------------page 42 --------------------------------
#define		ReadE2Page42Addr				0x2A        //6 to 10 num time freeze data
#define		WriteE2Page42Addr				0x2A

//---------------------------page 43 --------------------------------
#define		ReadE2Page43Addr				0x2B        //11 to 12 num time freeze data
#define		WriteE2Page43Addr				0x2B

//---------------------------page 44 --------------------------------
#define		ReadE2Page44Addr				0x2C        //1 to 5 num day freeze data
#define		WriteE2Page44Addr				0x2C

//---------------------------page 45 --------------------------------
#define		ReadE2Page45Addr				0x2D        //6 to 10 num day freeze data
#define		WriteE2Page45Addr				0x2D

//---------------------------page 46 --------------------------------
#define		ReadE2Page46Addr				0x2E        //11 to 15 num day freeze data
#define		WriteE2Page46Addr				0x2E

//---------------------------page 47 --------------------------------
#define		ReadE2Page47Addr				0x2F        //16 to 20 num day freeze data
#define		WriteE2Page47Addr				0x2F

//---------------------------page 48 --------------------------------
#define		ReadE2Page48Addr				0x30        //21 to 25 num day freeze data
#define		WriteE2Page48Addr				0x30

//---------------------------page 49 --------------------------------
#define		ReadE2Page49Addr				0x31        //26 to 30 num day freeze data
#define		WriteE2Page49Addr				0x31

//---------------------------page 50 --------------------------------
#define		ReadE2Page50Addr				0x32       //31 to 35 num day freeze data
#define		WriteE2Page50Addr				0x32

//---------------------------page 51 --------------------------------
#define		ReadE2Page51Addr				0x33        //36 to 40 num day freeze data
#define		WriteE2Page51Addr				0x33

//---------------------------page 52 --------------------------------
#define		ReadE2Page52Addr				0x34        //41 to 45 num day freeze data
#define		WriteE2Page52Addr				0x34

//---------------------------page 53 --------------------------------
#define		ReadE2Page53Addr				0x35        //46 to 50 num day freeze data
#define		WriteE2Page53Addr				0x35

//---------------------------page 54 --------------------------------
#define		ReadE2Page54Addr				0x36        //51 to 55 num day freeze data
#define		WriteE2Page54Addr				0x36

//---------------------------page 55 --------------------------------
#define		ReadE2Page55Addr				0x37        //56 to 60 num day freeze data
#define		WriteE2Page55Addr				0x37

//---------------------------page 56 --------------------------------
#define		ReadE2Page56Addr				0x38        //61 to 62 num day freeze data
#define		WriteE2Page56Addr				0x38


//---------------------------page 57 --------------------------------
#define		ReadE2Page57Addr				0x39       //1 to 16 num hour freeze data
#define		WriteE2Page57Addr				0x39       //


//---------------------------page 58 --------------------------------
#define		ReadE2Page58Addr				0x3A        //17 to 32 num hour freeze data
#define		WriteE2Page58Addr				0x3A 

//---------------------------page 59 --------------------------------
#define		ReadE2Page59Addr				0x3B        //33 to 48 num hour freeze data
#define		WriteE2Page59Addr				0x3B 

//---------------------------page 60 --------------------------------
#define		ReadE2Page60Addr				0x3C        //49 to 64 num hour freeze data
#define		WriteE2Page60Addr				0x3C

//---------------------------page 61 --------------------------------
#define		ReadE2Page61Addr				0x3D        //65 to 80 num hour freeze data
#define		WriteE2Page61Addr				0x3D

//---------------------------page 62 --------------------------------
#define		ReadE2Page62Addr				0x3E        //81 to 96 num hour freeze data
#define		WriteE2Page62Addr				0x3E

//========================================================================
//---------------------------page 63 --------------------------------
#define		ReadE2Page63Addr				0x3F        
#define		WriteE2Page63Addr				0x3F

//========================================================================

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif		//E2define.h
