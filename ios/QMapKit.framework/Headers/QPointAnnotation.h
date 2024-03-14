//
//  QPointAnnotation.h
//  QMapKit
//
//  Created by tabsong on 17/5/18.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import "QShape.h"
#import "QAnnotation.h"
#import <CoreLocation/CoreLocation.h>

/**
 * @brief 点标注数据. 代表一个经纬度点位置的点状覆盖物的数据
 */
@interface QPointAnnotation : QShape <QAnnotation>

/**
 *  @brief  经纬度
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  @brief  标题
 */
@property (copy) NSString *title;

/**
 *  @brief  副标题
 */
@property (copy) NSString *subtitle;

/**
 *  @brief  是否固定到屏幕坐标。默认为NO。运行时设置有效。
 *  1. 屏幕固定坐标是由 lockedScreenPoint 变量来指定，是在QMapView bounds 坐标系下。
 *  2. 固定后，coordinate 变量始终是 lockedScreenPoint 对应到地图上的经纬度坐标。
 *  3. 固定后，任何更新 coordinate变量均无效。
 */
@property (nonatomic, assign) BOOL lockedToScreen;

/**
 *  @brief  固定到的屏幕指定坐标, 是在QMapView bounds 坐标系下。当 lockedToScreen == YES是有效。默认为CGPointZero. 运行时设置有效。
 *  @note 最终在屏幕上的位置是由 lockedScreenPoint 和 annotatonView.centerOffset共同影响的。
 */
@property (nonatomic, assign) CGPoint lockedScreenPoint;

/**
 *  @brief  室内位置
 *
 * 添加完后修改无效
 */
@property (nonatomic, strong) QIndoorInfo *indoorInfo;

@end
