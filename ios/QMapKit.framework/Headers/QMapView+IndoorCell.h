//
//  QMapView+IndoorCell.h
//  QMapKit
//
//  Created by KeithCao on 2022/3/11.
//  Copyright © 2022 tencent. All rights reserved.
//

#import <QMapKit/QMapKit.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @brief  面样式的定义
 */
@interface QIndoorCellStyle : NSObject

/**
 *  @brief 面颜色
 */
@property (nonatomic, strong) UIColor *color;

@end

/**
 *  @brief  面样式的配置信息
 */
@interface QIndoorCellInfo : NSObject

/**
 *  @brief 面样式
 */
@property (nonatomic, strong) QIndoorCellStyle *style;

/**
 *  @brief 面id列表
 */
@property (nonatomic, strong) NSArray <NSString *> *regions;

@end


@interface QMapView (IndoorCell)

/**
 *  @brief 设置面样式, 需要在面所在室内图激活后再进行设置
 */
- (void)setIndoorCell:(NSArray<QIndoorCellInfo *> *)cellInfo;

/**
 *  @brief 清除自定义面样式(恢复默认样式), 需在面所在室内图激活时调用
 */
- (void)resetIndoorCell;

@end

NS_ASSUME_NONNULL_END
