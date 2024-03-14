//
//  QArc.h
//  QMapKit
//
//  Created by Keith Cao on 2020/11/19.
//  Copyright © 2020 tencent. All rights reserved.
//

#import "QOverlay.h"
#import "QShape.h"

/*
 *	@brief 该类用于定义一段弧线, 通常QArc是QArcView中持有的对象
 */
@interface QArc : QShape<QOverlay>

/**
 * @brief  区域外接矩形
 */
@property(nonatomic, readonly) QMapRect boundingMapRect;

/**
 *	@brief 	根据起始点、终点和途径点构建弧线
 *	@param 	startPoint 起始点经纬度坐标
 *	@param 	endPoint 终点经纬度坐标
 *	@param 	passedPoint 途径点经纬度坐标
 *	@return 新生成的弧线
 */
+(QArc *)arcWithStartPoint:(CLLocationCoordinate2D)startPoint endPoint:(CLLocationCoordinate2D)endPoint passedPoint:(CLLocationCoordinate2D)passedPoint;

/**
 *	@brief 	根据起始点、终点和途径点构建弧线
 *	@param 	startPoint 起始点经纬度坐标
 *	@param 	endPoint 终点经纬度坐标
 *	@param 	passedPoint 途径点经纬度坐标
 *	@return 新生成的弧线
 */
- (instancetype)initWithStartPoint:(CLLocationCoordinate2D)startPoint endPoint:(CLLocationCoordinate2D)endPoint passedPoint:(CLLocationCoordinate2D)passedPoint;

/**
 *	@brief 	根据起始点、终点和起始点切线角度构建弧线
 *	@param 	startPoint 起始点经纬度坐标
 *	@param 	endPoint 终点经纬度坐标
 *	@param 	tangentAngle 起始点切线与水平直线夹角
 *	@return 新生成的弧线
 */
+(QArc *)arcWithStartPoint:(CLLocationCoordinate2D)startPoint endPoint:(CLLocationCoordinate2D)endPoint tangentAngle:(double)tangentAngle;

/**
 *	@brief 	根据起始点、终点和起始点切线角度构建弧线
 *	@param 	startPoint 起始点经纬度坐标
 *	@param 	endPoint 终点经纬度坐标
 *	@param 	tangentAngle 起始点切线与水平直线夹角（逆时针方向为正);
 *				1）0< 夹角 < 180 时，顺时针方向画弧
 *				2）180 < 夹角 < 360 时，逆时针方向画弧
 *	@return 新生成的弧线
 */
- (instancetype)initWithStartPoint:(CLLocationCoordinate2D)startPoint endPoint:(CLLocationCoordinate2D)endPoint tangentAngle:(double)tangentAngle;

@end
