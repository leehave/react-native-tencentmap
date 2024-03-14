//
//  QMSSearchOptionTypes.h
//  QMapSearchKit
//
//  Created by Keith Cao on 2023/4/26.
//  Copyright © 2023 tencent. All rights reserved.
//

#ifndef QMSSearchOptionTypes_h
#define QMSSearchOptionTypes_h

#import <Foundation/Foundation.h>


/**
 *	@brief	门牌格式
 */
typedef NS_ENUM (NSInteger, QMSStreetNumberFormat){
	QMSStreetNumberFormatJoined = 0,			///< 拼接，街道名+号码。(默认：例：北四环西路66号)
	QMSStreetNumberFormatPlateNumberOnly,		///< 不拼接，只有号码。如：66号
	
};

/**
 *	@brief	货车类型
 */
typedef NS_ENUM (NSInteger, QMSTruckType){
	QMSTruckTypeMiniTruck = 1,		///< 微型货车
	QMSTruckTypeLightTruck,			///< 轻型货车
	QMSTruckTypeMediumTruck,		///< 中型货车
	QMSTruckTypeHeavyTruck			///< 重型货车
};

/**
 *	@brief	拖挂类型
 */
typedef NS_ENUM (NSInteger, QMSTruckTrailerType){
	QMSTruckTrailerTypeNone = 0,	///< 无
	QMSTruckTrailerTypeFlatbed,		///< 平板
	QMSTruckTrailerTypeCargoBox,	///< 货箱
	QMSTruckTrailerTypeSemi,		///< 半挂
	QMSTruckTrailerTypeFull			///< 全挂
	
};

/**
 *	@brief	货品类型
 */
typedef NS_ENUM (NSInteger, QMSTruckGoodsType){
	QMSTruckGoodsTypeRegular = 0,		///< 常规
	QMSTruckGoodsTypeDangerous			///< 危险品
};

/**
 *	@brief	车辆能源类型
 */
typedef NS_ENUM (NSInteger, QMSVehicleEnergyType){
	QMSVehicleEnergyTypeUnlimited = 0,		///< 不限
	QMSVehicleEnergyTypeDiesel,				///< 柴油
	QMSVehicleEnergyTypeHybrid,				///< 油电混合
	QMSVehicleEnergyTypeElectric,			///< 纯电
	QMSVehicleEnergyTypePetrol				///< 汽油
};


/**
 *	@brief	排放标准
 */
typedef NS_ENUM (NSInteger, QMSVehicleGasEmisStandard){
	QMSVehicleGasEmisStandardUnlimited = 0,		///< 不限
	QMSVehicleGasEmisStandardNationalI,			///< 国I
	QMSVehicleGasEmisStandardNationalII,		///< 国II
	QMSVehicleGasEmisStandardNationalIII,		///< 国III
	QMSVehicleGasEmisStandardNationalIV,		///< 国IV
	QMSVehicleGasEmisStandardNationalV,			///< 国V
	QMSVehicleGasEmisStandardNationalVI			///< 国VI
};

/**
 *	@brief	车牌颜色
 */
typedef NS_ENUM (NSInteger, QMSVehiclePlateColor){
	QMSVehiclePlateColorNone = 0,		///< 无
	QMSVehiclePlateColorBlue,			///< 蓝色
	QMSVehiclePlateColorYellow,			///< 黄色
	QMSVehiclePlateColorBlack,			///< 黑色
	QMSVehiclePlateColorWhite,			///< 白色
	QMSVehiclePlateColorGreen,			///< 绿色
	QMSVehiclePlateColorYellowGreen		///< 黄绿
};

/**
 *	@brief	通行证
 */
typedef NS_ENUM (NSInteger, QMSVehiclePassType){
	QMSVehiclePassTypeUnlimited = 0,	///< 无需考虑通行证
	QMSVehiclePassTypeOwnPass,			///< 有通行证
	QMSVehiclePassTypeNoPass,			///< 无通行证
	QMSVehiclePassTypeReservation		///< 预约通行证
	
};

/**
 *	@brief	路线标签返回类型
 */
typedef NS_ENUM (NSInteger, QMSRouteTagType){
	QMSRouteTagTypeAll = 0,			///< 返回全部标签v1+v2,中文标签混合返回
	QMSRouteTagTypeChinese			///< 返回全中文<=4字标签(仅包含v2，不包含解释性标签)
	
};

#endif /* QMSSearchOptionTypes_h */
