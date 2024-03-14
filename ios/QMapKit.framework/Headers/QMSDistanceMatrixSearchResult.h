//
//  QMSDistanceMatrixSearchResult.h
//  QMapSearchKit
//
//  Created by Keith Cao on 2023/4/25.
//  Copyright © 2023 tencent. All rights reserved.
//

#import "QMSSearchResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface QMSDistanceMatrixElementUnit : QMSBaseResult

/**
 *	@brief	起点到终点的距离，单位：米
 */
@property (nonatomic, assign) CGFloat distance;

/**
 *	@brief	表示从起点到终点的结合路况的时间，秒为单位
 *	@note 	步行/骑行方式（不计算耗时）以及起终点附近没有道路造成无法计算时，不返回本此节点
 */
@property (nonatomic,assign) CGFloat duration;

/**
 *	@brief	本对起终点计算的状态码
 *	@note	1) status 为 nil 时，计算结果正常
 *			2) status 值为 4 时，代表附近没有路，距离计算失败，此时distance为直线距离，预估耗时（duration）会返回 0
 */
@property (nonatomic, nullable, strong) NSNumber *status;

@end

/**
 *	@brief	距离矩阵计算结果的列
 */
@interface QMSDistanceMatrixElement : QMSBaseResult

/**
 *	@brief	每行多点到多点距离计算结果，元素为QMSDistanceMatrixElementUnit
 */
@property (nonatomic, copy) NSArray <QMSDistanceMatrixElementUnit *> *elements;

@end

/**
 *	@brief	距离矩阵计算结果
 *	@note	rows/elements结果数组结构说明请参考：https://lbs.qq.com/service/webService/webServiceGuide/webServiceMatrix
 */
@interface QMSDistanceMatrixSearchResult : QMSSearchResult

/**
 *	@brief	多点到多点距离计算总结果，元素为QMSDistanceMatrixElementUnit
 */
@property (nonatomic, copy) NSArray <QMSDistanceMatrixElement *> *rows;

@end

NS_ASSUME_NONNULL_END
