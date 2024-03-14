//
//  QOfflineMap.h
//  QMapKit
//
//  Created by Keith Cao on 2020/4/20.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QOfflineItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @enum QOfflineItemDownloadStatus 离线文件下载状态
 * @brief 离线文件下载状态
 * 1. 当下载状态为 QOfflineItemNone 表示无下载项目
 * 2. 当下载状态为 QOfflineItemDownloading 和 QOfflineItemDownloadCompleted，info 参数为字典
 * 3. 当下载状态为 QOfflineItemFailed 时，info 参数为NSError
 */
typedef NS_ENUM(NSInteger, QOfflineItemDownloadStatus)
{
    QOfflineItemDownloadNone,           ///< 无下载项目
    QOfflineItemDownloading,            ///< 下载中
    QOfflineItemDownloadCompleted,      ///< 下载完成
    QOfflineItemFailed                  ///< 失败
};

/**
 * @brief 离线地图下载回调;
 * @param downloadItem  下载的item;
 * @param status        下载的状态;
 * @param info          下载的附加信息;
 */
typedef void (^QOfflineMapDownloadBlock)(QOfflineItem *downloadItem, QOfflineItemDownloadStatus status, id info);

/**
 * @brief 离线地图类
 */
@interface QOfflineMap : NSObject

/**
 * @brief 获取离线地图单例
 */
+ (QOfflineMap *)sharedOfflineMap;

/**
 * @brief 离线文件列表, 其中包含全国概要、直辖市、省份和城市信息
 */
@property (nonatomic, readonly) NSArray <QOfflineItem *> *items;

/**
 * @brief 获取下载中的离线文件列表
 */
@property (nonatomic, readonly) NSArray <QOfflineItem *> *downloadingItems;

/**
 * @brief 加载离线地图函数，返回是否设置成功;
 *        调用此接口会重建所有数据, 请在回调中刷新持有的QOfflineItem;
 *        初次使用离线地图需运行此函数,否则城市数组或全国可能为空值;
 */
- (void)reloadItems:(void (^)(BOOL setUpSuccess))callback;

/**
 * @brief 下载单个离线文件
 */
- (void)downloadItem:(QOfflineItem *)item callback:(QOfflineMapDownloadBlock)callback;

/**
 * @brief 取消下载
 */
- (void)cancelDownload:(QOfflineItem *)item;

/**
 * @brief 删除单个离线文件
 */
- (void)deleteItem:(QOfflineItem *)item;

@end

NS_ASSUME_NONNULL_END
