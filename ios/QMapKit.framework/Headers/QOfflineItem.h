//
//  QOfflineItem.h
//  QMapKit
//
//  Created by Keith Cao on 2020/4/20.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @enum QOfflineItemStatus
 * @brief 离线文件状态
 */
typedef NS_ENUM(NSInteger, QOfflineItemStatus)
{
    QOfflineItemStatusNone,         ///< 不存在
    QOfflineItemStatusUpdated,      ///< 已更新
    QOfflineItemStatusOutdated      ///< 已过期
};

/**
 * @brief 离线文件类
 */
@interface QOfflineItem : NSObject

/// 名字
@property (nonatomic, copy, readonly) NSString *name;

/// 拼音
@property (nonatomic, copy, readonly) NSString *pinyin;

/// 数据大小
@property (nonatomic, assign, readonly) long long size;

/// 状态
@property (nonatomic, assign, readonly) QOfflineItemStatus status;

@end

/**
 * @brief 省份类, 省份不支持下载
 */
@interface QOfflineProvince : QOfflineItem

/// 省份包含的离线文件
@property (nonatomic, strong) NSArray <QOfflineItem *> *items;

@end

/**
 * @brief 全国概要类
 */
@interface QOfflineNation : QOfflineItem

@end

NS_ASSUME_NONNULL_END
