//
//  QMSDistanceMatrixSearchOption.h
//  QMapSearchKit
//
//  Created by Keith Cao on 2023/4/25.
//  Copyright © 2023 tencent. All rights reserved.
//

#import "QMSSearchOption.h"
#import "QMSSearchOptionTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *	@brief 距离矩阵计算检索
 */
@interface QMSDistanceMatrixSearchOption : QMSSearchOption

/**
 * 	@brief	起点坐标
 * 	@Note	格式： lat,lng,[header],[roadtype],[speed],[accuracy],[timestamp]｜lat,lng,[header],[roadtype],[speed],[accuracy],[timestamp]…
			(经度与纬度用英文逗号分隔，坐标间用英文分号分隔)
			[必填]lat 为纬度，lng 为经度
			[选填] header 为车头方向（正北为0度，顺时针一周为360度）
			如下参数为前序点传参，仅在驾车(driving)模式下生效
			[选填] roadtype 为道路类型，取值：0 不考虑道路类型、1 在桥上、2 在桥下、3 在主路、4 在辅路、5 在对面、6 桥下主路、7 桥下辅路
			[选填] speed 为速度，无具体值时可传-1
			[选填] accuracy 为GPS精度，单位：毫米，无具体值时可传0
			[选填] timestamp 为时间戳，精确到秒，请传真实时间戳，否则前序点会不生效
			注意:
			1、 前序点之间使用“｜”分隔，前序点最多支持设置5个（包含起点），最后一个点会作为此次计算的起点
			2、起点经纬度附近5公里内没有道路，会计算失败，返回“存在无法吸附的坐标点”
			个数限制:多对一计算<=200个，多对多计算from和to坐标数乘积<=625且单侧<=50个
 *			示例: 例1：from=39.071510,117.190091
 				例2：from=39.071510,117.190091,270;39.108951,117.279396,180
 				例3:	from=39.829647,116.422462,-1,0,-1,0,1639108623|39.830553,116.422924,-1,0,-1,0,1639108628|39.831261,116.423289,-1,0,-1,0,1639108633
 */
@property (nonatomic, copy) NSString *from;


/**
 * 	@brief	终点坐标
 * 	@Note	格式： lat,lng;lat,lng…
			(经度与纬度用英文逗号分隔，坐标间用英文分号分隔)
			个数限制： 一对多计算<=200个，多对多计算from和to坐标数乘积<=625且单侧<=50个
			注意：终点经纬度附近5公里内没有道路，会计算失败，返回“存在无法吸附的坐标点”
 *			示例:	 to=39.071510,117.190091;40.007632,116.389160
 */
@property (nonatomic, copy) NSString *to;


/**
 *	@brief	计算方式，取值: driving; walking; bicycling; trucking。例如 mode = driving
 */
@property (nonatomic, copy) NSString *mode;

@end


/**
 *	@brief	货车距离矩阵计算参数
 */
@interface QMSTruckDistanceMatrixSearchOption : QMSDistanceMatrixSearchOption

/**
 *	@brief 货车类型，默认轻型（QMSTruckTypeLightTruck）
 */
@property (nonatomic, assign) QMSTruckType	size;

/**
 *	@brief	车辆高度，单位：米 ，默认1.8
 */
@property (nonatomic, assign) CGFloat	height;

/**
 *	@brief	车辆宽度度，单位：米 ，默认1.9
 */
@property (nonatomic, assign) CGFloat	width;

/**
 *	@brief	车辆总重，单位：吨，默认2.5
 */
@property (nonatomic, assign) CGFloat	weight;

/**
 *	@brief	车辆长度，单位：米，默认4.2
 */
@property (nonatomic, assign) CGFloat	length;

/**
 *	@brief	核定截重，单位：吨，默认2吨
 */
@property (nonatomic, assign) CGFloat	load;

/**
 *	@brief	轴重，单位：吨，默认2
 */
@property (nonatomic, assign) CGFloat	axle_weight;

/**
 *	@brief	轴数，默认2
 */
@property (nonatomic, assign) CGFloat	axle_count;

/**
 *	@brief	拖挂类型：默认QMSTruckTrailerTypeNone
 */
@property (nonatomic, assign) QMSTruckTrailerType	trailer_type;

/**
 *	@brief	货品类型：默认QMSTruckGoodsTypeRegular
 */
@property (nonatomic, assign) QMSTruckGoodsType	goods_type;

/**
 *	@brief	能源类型：默认QMSVehicleEnergyTypeUnlimited
 */
@property (nonatomic, assign) QMSVehicleEnergyType	energy_type;

/**
 *	@brief	排放标准：默认QMSVehicleGasEmisStandardUnlimited
 */
@property (nonatomic, assign) QMSVehicleGasEmisStandard	gas_emisstand;

/**
 *	@brief	排放标准：默认QMSVehiclePlateColorBlue
 */
@property (nonatomic, assign) QMSVehiclePlateColor	plate_color;

/**
*	@brief	排放标准：默认QMSVehiclePassTypeUnlimited
*/
@property (nonatomic, assign) QMSVehiclePassType	pass_type;

/**
 *	@brief	车牌号,当缺省时，算路不考虑政策性区域限行
 */
@property (nonatomic, copy) NSString	*plate_number;

@end


NS_ASSUME_NONNULL_END
