//
//  QMSSearcher.h
//  QMapSearchKit
//
//  Created by fan on 2019/3/14.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QMSSearchOption.h"
#import "QMSSearchResult.h"
#import "QMSSearchError.h"
#import "QMSDistanceMatrixSearchOption.h"
#import "QMSDistanceMatrixSearchResult.h"

NS_ASSUME_NONNULL_BEGIN

@protocol QMSSearchDelegate;

/*!
 *  @brief  Search检索的主入口
 */
@interface QMSSearcher : NSObject

/*!
 *  @brief  实现QMSSearchDelegate协议的对象
 */
@property (nonatomic, weak) id<QMSSearchDelegate> delegate;

/*!
 *  @brief  QMSSearcher初始化函数
 *
 *  @param delegate 实现QMSSearchDelegate协议的对象
 *
 *  @return QMSSearcher对象
 */
- (instancetype)initWithDelegate:(id<QMSSearchDelegate>)delegate;

/**
 * @brief 取消所有未回调的请求，触发错误回调。
 *   error 对应的 domain 为 QMSSearchErrorDomain
 *            code 为 QMSSearchErrorCancelled = -1
 */
- (void)cancelAllRequests;


/*!
 *  @brief  查询步行路线
 *
 *  @param wakingRouteSearchOption 查询选项
 *
 */
- (void)searchWithWalkingRouteSearchOption:(QMSWalkingRouteSearchOption *)wakingRouteSearchOption NS_SWIFT_NAME(searchWithWalkingRouteSearchOption(_:));

/*!
 *  @brief  查询骑行路线
 *
 *  @param bicyclingRouteSearchOption 查询选项
 *
 */
- (void)searchWithBicyclingRouteSearchOption:(QMSBicyclingRouteSearchOption *)bicyclingRouteSearchOption NS_SWIFT_NAME(searchWithBicyclingRouteSearchOption(_:));

/*!
 *  @brief  根据poi查询接口查询poi数据
 *
 *  @param poiSearchOption 查询选项, 参考QMSPoiSearchOption属性字段
 *
 */
- (void)searchWithPoiSearchOption:(QMSPoiSearchOption *)poiSearchOption NS_SWIFT_NAME(searchWithPoiSearchOption(_:));

/*!
 *  @brief  根据poi 周边推荐Explore查询接口查询poi数据
 *
 *  @param poiExploreSearchOption 查询选项, 参考QMSPoiExploreSearchOption属性字段
 *
 */
- (void)searchWithPoiExploreSearchOption:(QMSPoiExploreSearchOption *)poiExploreSearchOption NS_SWIFT_NAME(searchWithPoiExploreSearchOption(_:));

/*!
 *  @brief  根据poi detail查询接口查询poi数据
 *
 *  @param poiDetailSearchOption 查询选项, 参考QMSPoiDetailSearchOption属性字段
 *
 */
- (void)searchWithPoiDetailSearchOption:(QMSPoiDetailSearchOption *)poiDetailSearchOption NS_SWIFT_NAME(searchWithPoiDetailSearchOption(_:));


/*!
 *  @brief  根据suggestion接口查询, 用于获取输入关键字的补完与提示
 *
 *  @param suggestionSearchOption 查询选项, 参考QMSSuggestionSearchOption属性字段
 *
 */
- (void)searchWithSuggestionSearchOption:(QMSSuggestionSearchOption *)suggestionSearchOption NS_SWIFT_NAME(searchWithSuggestionSearchOption(_:));

/*!
 *  @brief  根据geocoder接口查询, 提供由 坐标 到 坐标所在位置的文字描述 的转换
 *
 *  @param reverseGeoCodeSearchOption 查询选项, 参考QMSReverseGeoCodeSearchOption属性字段
 *
 */
- (void)searchWithReverseGeoCodeSearchOption:(QMSReverseGeoCodeSearchOption *)reverseGeoCodeSearchOption NS_SWIFT_NAME(searchWithReverseGeoCodeSearchOption(_:));

/*!
 *  @brief  根据geocoder接口查询, 提供由地址描述到所述位置坐标的转换，与逆地址解析的过程正好相反
 *
 *  @param geoCodeSearchOption 查询选项, 参考QMSGeoCodeSearchOption属性字段
 *
 */
- (void)searchWithGeoCodeSearchOption:(QMSGeoCodeSearchOption *)geoCodeSearchOption NS_SWIFT_NAME(searchWithGeoCodeSearchOption(_:));


/*!
 *  @brief  查询驾车路线
 *
 *  @param drivingRouteSearchOption 查询选项
 *
 */
- (void)searchWithDrivingRouteSearchOption:(QMSDrivingRouteSearchOption *)drivingRouteSearchOption NS_SWIFT_NAME(searchWithDrivingRouteSearchOption(_:));

/*!
 *  @brief  查询货车路线
 *
 *  @param truckingRouteSearchOption 查询选项
 *
 */
- (void)searchWithTruckingRouteSearchOption:(QMSTruckingRouteSearchOption *)truckingRouteSearchOption NS_SWIFT_NAME(searchWithTruckingRouteSearchOption(_:));

/*!
 *  @brief  查询公交路线
 *
 *  @param busingRouteSearchOption 查询选项
 *
 */
- (void)searchWithBusingRouteSearchOption:(QMSBusingRouteSearchOption *)busingRouteSearchOption NS_SWIFT_NAME(searchWithBusingRouteSearchOption(_:));

/*!
 *  @brief  查询全部行政区划列表
 *
 *  list接口： 获取全部行政区划数据
 *
 *  @param districtListSearchOption 查询选项
 *
 */
- (void)searchWithDistrictListSearchOption:(QMSDistrictListSearchOption *)districtListSearchOption NS_SWIFT_NAME(searchWithDistrictListSearchOption(_:));

/*!
 *  @brief  查询指定行政区划的子级行政区划
 *
 *  getchildren接口：获取指定行政区划的子级行政区划
 *
 *  @param districtChildrenSearchOption 查询选项
 *
 */
- (void)searchWithDistrictChildrenSearchOption:(QMSDistrictChildrenSearchOption *)districtChildrenSearchOption NS_SWIFT_NAME(searchWithDistrictChildrenSearchOption(_:));

/*!
 *  @brief  查询指定关键词的行政区划
 *
 *  search接口：根据关键词搜索行政区划
 *
 *  @param districtSearchSearchOption 查询选项
 *
 */
- (void)searchWithDistrictSearchSearchOption:(QMSDistrictSearchSearchOption *)districtSearchSearchOption NS_SWIFT_NAME(searchWithDistrictSearchSearchOption(_:));

/*!
 *  @brief  查询距离矩阵计算
 *
 *  search接口：距离矩阵计算
 *
 *  @param distanceMatrixSearchOption 查询选项
 *
 */
- (void)searchWithDistanceMatrixSearchSearchOption:(QMSDistanceMatrixSearchOption *)distanceMatrixSearchOption NS_SWIFT_NAME(distanceMatrixSearchOption(_:));

@end

/*!
 *  @brief  Search检索的协议
 */
@protocol QMSSearchDelegate <NSObject>

@optional

/*!
 *  @brief  查询出现错误
 *
 *  @param searchOption 查询参数
 *  @param error        错误
 */
- (void)searchWithSearchOption:(QMSSearchOption *)searchOption didFailWithError:(NSError*)error;

/*!
 *  @brief  步行路径结果回调
 *
 *  @param walkingRouteSearchOption 查询参数
 *  @param walkingRouteSearchResult 查询结果
 */
- (void)searchWithWalkingRouteSearchOption:(QMSWalkingRouteSearchOption *)walkingRouteSearchOption didRecevieResult:(QMSWalkingRouteSearchResult *)walkingRouteSearchResult;

/*!
 *  @brief  骑行路径结果回调
 *
 *  @param bicyclingRouteSearchOption 查询参数
 *  @param bicyclingRouteSearchResult 查询结果
 */
- (void)searchWithBicyclingRouteSearchOption:(QMSBicyclingRouteSearchOption *)bicyclingRouteSearchOption didRecevieResult:(QMSBicyclingRouteSearchResult *)bicyclingRouteSearchResult;

/*!
 *  @brief  poi查询结果回调函数
 *
 *  @param poiSearchOption 查询参数
 *  @param poiSearchResult 查询结果
 */
- (void)searchWithPoiSearchOption:(QMSPoiSearchOption *)poiSearchOption didReceiveResult:(QMSPoiSearchResult *)poiSearchResult;

/*!
 *  @brief  poi 周边推荐Explore查询结果回调函数
 *
 *  @param poiExploreSearchOption 查询参数
 *  @param poiSearchResult 查询结果
 */
- (void)searchWithPoiExploreSearchOption:(QMSPoiExploreSearchOption *)poiExploreSearchOption didReceiveResult:(QMSPoiSearchResult *)poiSearchResult;

/*!
 *  @brief  poi detail查询结果回调函数
 *
 *  @param poiDetailSearchOption 查询参数
 *  @param poiSearchResult 查询结果
 */
- (void)searchWithPoiDetailSearchOption:(QMSPoiDetailSearchOption *)poiDetailSearchOption didReceiveResult:(QMSPoiSearchResult *)poiSearchResult;

/*!
 *  @brief  关键字的补完与提示回调接口
 *
 *  @param suggestionSearchOption 查询参数
 *  @param suggestionSearchResult 查询结果
 */
- (void)searchWithSuggestionSearchOption:(QMSSuggestionSearchOption *)suggestionSearchOption didReceiveResult:(QMSSuggestionResult *)suggestionSearchResult;

/*!
 *  @brief  逆地理解析(坐标位置描述)结果回调接口
 *
 *  @param reverseGeoCodeSearchOption 查询参数
 *  @param reverseGeoCodeSearchResult 查询结果
 */
- (void)searchWithReverseGeoCodeSearchOption:(QMSReverseGeoCodeSearchOption *)reverseGeoCodeSearchOption didReceiveResult:(QMSReverseGeoCodeSearchResult *)reverseGeoCodeSearchResult;

/*!
 *  @brief  地址解析(地址转坐标)结果回调接口
 *
 *  @param geoCodeSearchOption 查询参数
 *  @param geoCodeSearchResult 查询结果
 */
- (void)searchWithGeoCodeSearchOption:(QMSGeoCodeSearchOption *)geoCodeSearchOption didReceiveResult:(QMSGeoCodeSearchResult *)geoCodeSearchResult;


/*!
 *  @brief  驾车路径结果回调
 *
 *  @param drivingRouteSearchOption 查询参数
 *  @param drivingRouteSearchResult 查询结果
 */
- (void)searchWithDrivingRouteSearchOption:(QMSDrivingRouteSearchOption *)drivingRouteSearchOption didRecevieResult:(QMSDrivingRouteSearchResult *)drivingRouteSearchResult;

/*!
 *  @brief  货车路径结果回调
 *
 *  @param truckingRouteSearchOption 查询参数
 *  @param truckingRouteSearchResult 查询结果
 */
- (void)searchWithTruckingRouteSearchOption:(QMSTruckingRouteSearchOption *)truckingRouteSearchOption didRecevieResult:(QMSTruckingRouteSearchResult *)truckingRouteSearchResult;

/*!
 *  @brief  公交路径结果回调
 *
 *  @param busingRouteSearchOption 查询参数
 *  @param busingRouteSearchResult 查询结果
 */
- (void)searchWithBusingRouteSearchOption:(QMSBusingRouteSearchOption *)busingRouteSearchOption didRecevieResult:(QMSBusingRouteSearchResult *)busingRouteSearchResult;

/*!
 *  @brief  行政区划结果回调
 *
 *  3种行政区划的查询都使用此回调
 *
 *  @param districtSearchOption 查询参数
 *  @param districtSearchResult 查询结果
 */
- (void)searchWithDistrictSearchOption:(QMSDistrictBaseSearchOption *)districtSearchOption didRecevieResult:(QMSDistrictSearchResult *)districtSearchResult;

/*!
 *  @brief  距离矩阵计算结果回调
 *
 *  @param distanceMatrixSearchOption 查询参数
 *  @param distanceMatrixSearchResult 查询结果
 */
- (void)searchWithDistanceMatrixSearchOption:(QMSDistanceMatrixSearchOption *)distanceMatrixSearchOption didRecevieResult:(QMSDistanceMatrixSearchResult *)distanceMatrixSearchResult;

@end

NS_ASSUME_NONNULL_END
