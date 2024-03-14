//
//  QMSSearchResult.h
//  QMapSearchKit
//
//  Created by xfang on 14/11/5.
//  Copyright (c) 2014年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @brief 交通方式: 步行
 */
FOUNDATION_EXPORT NSString * const kQMSRouteWalkingMode;


/*!
 *  @brief 检索结果的状态码
 */
typedef NSInteger QMSResultCode;

#pragma mark -

/*!
 *  @brief 检索结果的基类
 */
@interface QMSBaseResult : NSObject <NSCopying, NSCoding>

@end

/*!
 *  @brief 检索结果
 */
@interface QMSSearchResult : QMSBaseResult

/*!
 *  @brief  状态码, 0为成功
 */
@property (nonatomic, assign) QMSResultCode status;

/*!
 *  @brief  状态说明
 */
@property (nonatomic, copy) NSString *message;

/*!
 *  @brief  本次请求的唯一标识，由系统自动生成，用于追查结果有异常时使用
 */
@property (nonatomic, copy) NSString *request_id;

@end

#pragma mark - POI Result

typedef NS_ENUM(NSInteger, QMSPoiType)
{
    QMSPoiNormalType                  = 0, //普通POI
    QMSPoiBusStopType                 = 1, //公交车站
    QMSPoiMRTType                     = 2, //地铁站
    QMSPoiBusLineType                 = 3, //公交路线
    QMSPoiAdministrativeDivisionType  = 4, //行政区划
};

/*!
 *  @brief  行政区划信息
 */
@interface QMSPoiAdInfo : QMSBaseResult

/*!
 *  @brief  邮政编码
 */
@property (nonatomic, strong) NSNumber *adcode;

/*!
 *  @brief  省
 */
@property (nonatomic, copy) NSString *province;

/*!
 *  @brief  市
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  区
 */
@property (nonatomic, copy) NSString *district;

@end

/*!
 *  @brief  POI展示数据
 */
@interface QMSPoiData : QMSBaseResult

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  poi名称
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  地址
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  @brief  电话
 */
@property (nonatomic, copy) NSString *tel;

/*!
 *  @brief  POI分类
 */
@property (nonatomic, copy) NSString *category;

/*!
 *  @brief  POI分类编码，需在额外字段added_fields中填入category_code
 */
@property (nonatomic, copy) NSString *category_code;

/*!
 *  @brief  POI类型，值说明：0:普通POI / 1:公交车站 / 2:地铁站 / 3:公交线路 / 4:行政区划
 */
@property (nonatomic, assign) QMSPoiType type;

/*!
 *  @brief  坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  轮廓，坐标数组，面积较大的POI会有，如住宅小区。数组里为CLLocationCoordinate2D类型数据  非必有字段
 */
@property (nonatomic, strong) NSArray <NSValue *> *boundary DEPRECATED_ATTRIBUTE;

/*!
 *	@brief 距离，单位： 米，在周边搜索、城市范围搜索传入定位点时返回
 */
@property (nonatomic, assign) double _distance;

/*!
 *  @brief  行政区划信息
 */
@property (nonatomic, strong) QMSPoiAdInfo *ad_info;

@end


/*!
 *  @brief  子Poi信息
 */
@interface QMSPoiSubData : QMSBaseResult

/*!
 *  @brief  父Poi ID
 */
@property (nonatomic, copy) NSString *parent_id;

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  poi名称
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  地址
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  @brief  电话
 */
@property (nonatomic, copy) NSString *tel;

/*!
 *  @brief  POI分类
 */
@property (nonatomic, copy) NSString *category;

/*!
 *  @brief  POI分类编码，需在额外字段added_fields中填入category_code
 */
@property (nonatomic, copy) NSString *category_code;

/*!
 *  @brief  POI类型，值说明：0:普通POI / 1:公交车站 / 2:地铁站 / 3:公交线路 / 4:行政区划
 */
@property (nonatomic, assign) QMSPoiType type;

/*!
 *  @brief  坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  行政区划信息
 */
@property (nonatomic, strong) QMSPoiAdInfo *ad_info;

@end

/*!
 *  @brief  Poi检索结果
 */
@interface QMSPoiSearchResult : QMSSearchResult

/*!
 *  @brief  本次搜索结果总数
 */
@property (nonatomic, assign) NSUInteger count;

/*!
 *  @brief  搜索结果POI数组，每项为一个POI(QMSPoiData)对象
 */
@property (nonatomic, strong) NSArray <QMSPoiData *> *dataArray;

/*!
 *  @brief  子地点列表，仅在输入参数get_subpois=1时返回. 每项为一个POI(QMSPoiSubData)对象
 */
@property (nonatomic, nullable,strong) NSArray <QMSPoiSubData *> *sub_pois;

@end

#pragma mark - Suggestion Result

/*!
 *  @brief  关键词提示检索Poi数据
 */
@interface QMSSuggestionPoiData : QMSBaseResult

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  提示文字
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  地址详细描述
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  @brief  邮政编码
 */
@property (nonatomic, strong) NSNumber *adcode;

/*!
 *  @brief  省
 */
@property (nonatomic, copy) NSString *province;

/*!
 *  @brief  市
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  区/县，当type（POI类型）为3（公交线路）时，district由city补全
 */
@property (nonatomic, copy) NSString *district;

/*!
 *  @brief  POI类型，值说明：0:普通POI / 1:公交车站 / 2:地铁站 / 3:公交线路 / 4:行政区划
 */
@property (nonatomic, assign) QMSPoiType type;

/*!
 *	@brief 距离，单位： 米，传入location（定位坐标）参数时，返回定位坐标到各POI的距离
 */
@property (nonatomic, assign) double _distance;

/*!
 *  @brief  坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  POI分类
 */
@property (nonatomic, copy) NSString *category;

/*!
 *  @brief  POI分类编码，需在额外字段added_fields中填入category_code
 */
@property (nonatomic, nullable, copy) NSString *category_code;

@end

/*!
 *  @brief  关键词提示检索子Poi数据
 */
@interface QMSSuggestionSubPoiData : QMSBaseResult

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, copy) NSString *parent_id;

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, copy) NSString *id_;


/*!
 *  @brief  提示文字
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  地址详细描述
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  @brief  坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  邮政编码
 */
@property (nonatomic, strong) NSNumber *adcode;

/*!
 *  @brief  市
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  POI分类
 */
@property (nonatomic, copy) NSString *category;

/*!
 *  @brief  POI分类编码，需在额外字段added_fields中填入category_code
 */
@property (nonatomic, nullable, copy) NSString *category_code;

@end

/*!
 *  @brief  关键词提示检索结果
 */
@interface QMSSuggestionResult : QMSSearchResult

/*!
 *  @brief  本次搜索结果总数
 */
@property (nonatomic, assign) NSUInteger count;

/*!
 *  @brief  提示词数组，每项为一个POI(QMSSuggestionPoiData)对象
 */
@property (nonatomic, copy) NSArray <QMSSuggestionPoiData *> *dataArray;

/*!
 *  @brief  子地点列表，仅在输入参数get_subpois=1时返回. 每项为一个POI(QMSSuggestionSubPoiData)对象
 */
@property (nonatomic, nullable, copy) NSArray <QMSSuggestionSubPoiData *> *sub_pois;

@end

#pragma mark - Reverse Geo Code

/*!
 *  @brief  优化格式后的地址描述
 */
@interface QMSReGeoCodeFormattedAddresses : QMSBaseResult

/*!
 *  @brief  经过腾讯地图优化过的描述方式，更具人性化特点
 */
@property (nonatomic, nullable, copy) NSString *recommend;

/*!
 *  @brief  大致位置，可用于对位置的粗略描述
 */
@property (nonatomic, nullable, copy) NSString *rough;

/*!
 *  @brief  标准地址
 */
@property (nonatomic, nullable, copy) NSString *standard_address;

@end

/*!
 *  @brief  检索地址部件
 */
@interface QMSAddressComponent : QMSBaseResult

/*!
 *  @brief  国家
 */
@property (nonatomic, nullable, copy) NSString *nation;

/*!
 *  @brief  省
 */
@property (nonatomic, copy) NSString *province;

/*!
 *  @brief  市
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  区(可能为空)
 */
@property (nonatomic, nullable, copy) NSString *district;

/*!
 *  @brief  街道(可能为空)
 */
@property (nonatomic, nullable, copy) NSString *street;

/*!
 *  @brief  门牌(可能为空)
 */
@property (nonatomic, nullable, copy) NSString *street_number;

@end

/*!
 *  @brief  行政区划信息
 */
@interface QMSReGeoCodeAdInfo : QMSBaseResult

/*!
 *  @brief  行政区划代码
 */
@property (nonatomic, copy) NSString *nation_code;

/*!
 *  @brief  行政区划代码
 */
@property (nonatomic, copy) NSString *adcode;

/*!
 *  @brief  行政区划名称
 */
@property (nonatomic, copy) NSString *name;

/*!
 *  @brief  行政区划中心点坐标
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  国家
 */
@property (nonatomic, copy) NSString *nation;

/*!
 *  @brief  省 / 直辖市
 */
@property (nonatomic, copy) NSString *province;

/*!
 *  @brief  市 / 地级区 及同级行政区划
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  区 / 县级市 及同级行政区划(可能为空)
 */
@property (nonatomic, nullable, copy) NSString *district;

/*!
 *	@brief	城市代码，由国家码+行政区划代码（提出城市级别）组合而来，总共为9位
 */
@property (nonatomic, copy) NSString *city_code;

/*!
 *  @brief    电话区号
 */
@property (nonatomic, nullable, copy) NSString *phone_area_code;

@end

/*!
 *  @brief  知名区域，如商圈或人们普遍认为有较高知名度的区域
 */
@interface QMSReGeoCodeFamousArea : QMSBaseResult

/*!
 *  @brief  唯一标识
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  名称/标题
 */
@property (nonatomic, nullable, copy) NSString *title;

/*!
 *  @brief  坐标
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  此参考位置到输入坐标的直线距离
 */
@property (nonatomic, assign) double _distance;

/*!
 *  @brief  此参考位置到输入坐标的方位关系，如：北、南、内
 */
@property (nonatomic, nullable, copy) NSString *_dir_desc;

@end

/*!
 *  @brief  坐标相对位置参考
 */
@interface QMSReGeoCodeAddressReference : QMSBaseResult

/*!
 *  @brief  知名区域，如商圈或人们普遍认为有较高知名度的区域
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *famous_area;

/*!
 *  @brief  一级地标，可识别性较强、规模较大的地点、小区等
    【注】对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *landmark_l1;

/*!
 *  @brief  二级地标，较一级地标更为精确，规模更小
    【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *landmark_l2;

/*!
 *  @brief  乡镇街道    【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *town;

/*!
 *  @brief  街道    【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *street;

/*!
 *  @brief  门牌    【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *street_number;

/*!
 *  @brief  水系   【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *water;

/*!
 *  @brief  交叉路口     【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *crossroad;

/*!
 *  @brief  商圈     【注】：目前与famous_area一致
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *business_area;

/*!
 *  @brief  海洋信息     【注】：对象结构同 famous_area
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFamousArea *ocean;

@end

/*!
 *  @brief  POI行政区划信息
 */
@interface QMSReGeoCodePoiAdInfo : QMSBaseResult

/*!
 *  @brief  行政区划代码
 */
@property (nonatomic, copy) NSString *adcode;

/*!
 *  @brief  省
 */
@property (nonatomic, nullable, copy) NSString *province;

/*!
 *  @brief  市
 */
@property (nonatomic, copy) NSString *city;

/*!
 *  @brief  区(可能为空)
 */
@property (nonatomic, nullable, copy) NSString *district;

@end

/*!
 *  @brief  逆地址解析POI
 */
@interface QMSReGeoCodePoi : QMSBaseResult

/*!
 *  @brief  POI唯一标识
 */
@property (nonatomic, nullable, copy) NSString *id_;

/*!
 *  @brief  poi名称
 */
@property (nonatomic, nullable, copy) NSString *title;

/*!
 *  @brief  地址
 */
@property (nonatomic, nullable, copy) NSString *address;

/*!
 *  @brief  POI分类
 */
@property (nonatomic, nullable, copy) NSString *category;

/*!
 *  @brief  坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  该POI到逆地址解析传入的坐标的直线距离
 */
@property (nonatomic, assign) double _distance;

/*!
 *  @brief  行政区划信息
 */
@property (nonatomic, nullable) QMSReGeoCodePoiAdInfo *ad_info;

/*!
 *  @brief  逆地址解析传入的坐标的相对方位描述
 */
@property (nonatomic, nullable, copy) NSString *_dir_desc;


@end

/*!
 *  @brief  逆地址检索结果
 */
@interface QMSReverseGeoCodeSearchResult : QMSSearchResult

/*!
 *  @brief  地址描述
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  @brief  位置描述
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeFormattedAddresses *formatted_addresses;

/*!
 *  @brief  地址部件，address不满足需求时可自行拼接
 */
@property (nonatomic, strong) QMSAddressComponent *address_component;

/*!
 *  @brief  行政区划信息
 */
@property (nonatomic, strong) QMSReGeoCodeAdInfo *ad_info;

/*!
 *  @brief  坐标相对位置参考
 */
@property (nonatomic, nullable, strong) QMSReGeoCodeAddressReference *address_reference;

/*!
 *  @brief  POI数组，对象中每个子项为一个POI(QMSReGeoCodePoi)对象
 */
@property (nonatomic, nullable, strong) NSArray <QMSReGeoCodePoi *> *poisArray;

/*!
 *  @brief  查询的周边poi的总数
 */
@property (nonatomic, assign) NSUInteger poi_count;

@end

#pragma mark - Geo code

/*!
 *  @brief  地址解析行政区划信息
 */
@interface QMSGeoCodeAdInfo : QMSBaseResult

/*!
 *  @brief  行政区划代码
 */
@property (nonatomic, copy) NSString *adcode;

@end

/*!
 *  @brief  地址解析检索结果
 */
@interface QMSGeoCodeSearchResult : QMSSearchResult

/*!
 *  @brief  解析到的坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  解析后的地址部件
 */
@property (nonatomic, strong) QMSAddressComponent *address_components;

/*!
 *  @brief  行政区划信息
 */
@property (nonatomic, strong) QMSGeoCodeAdInfo *ad_info;

/*!
 *  @brief  解析精度级别，分为11个级别，一般>=9即可采用（定位到点，精度较高） 也可根据实际业务需求自行调整，完整取值表见下文。
 *
 *  level（解析级别）取值表：
 *  值    解析级别
 *  1    城市
 *  2    区、县
 *  3    乡镇、街道
 *  4    村、社区
 *  5    开发区
 *  6    热点区域、商圈
 *  7    道路
 *  8    道路附属点：交叉口、收费站、出入口等
 *  9    门址
 *  10    小区、大厦
 *  11    POI点
 */
@property (nonatomic, assign) NSInteger level;

/*!
 *  @brief  可信度参考：值范围 1 <低可信> - 10 <高可信>
 *
 *     我们根据用户输入地址的准确程度，在解析过程中，将解析结果的可信度(质量)，由低到高，分为1 - 10级，
 *     该值>=7时，解析结果较为准确，<7时，会存各类不可靠因素，开发者可根据自己的实际使用场景，对于解析质量的实际要求，进行参考。
 */
@property (nonatomic, assign) NSUInteger reliability;

@end

#pragma mark - Walking & Bicyling & Driving

@class QMSRoutePlan, QMSRouteStep;

/*!
 *  @brief  步行路线规划的检索结果
 */
@interface QMSWalkingRouteSearchResult : QMSSearchResult

/*!
 *  @brief  路线方案的数组, 元素类型为QMSRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSRoutePlan *> *routes;

@end

#pragma mark - Bicycling 的详情

/*!
 *  @brief  骑行路线规划的检索结果
 */
@interface QMSBicyclingRouteSearchResult : QMSSearchResult

/*!
 *  @brief  路线方案的数组, 元素类型为QMSRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSRoutePlan *> *routes;

@end

#pragma mark - Driving 的详情

/*!
 *	@brief 途径城市信息
 */
@interface QMSRoutePlanCityInfo : QMSBaseResult

/*!
 *	@brief	途经的行政区划代码, 到区级
 */
@property (nonatomic, assign) NSInteger adcode;

@end

/*!
 *  @brief  限行信息
 */
@interface QMSDriveRestriction : QMSBaseResult
/*!
 *  @brief  限行状态码：
 *
 *  0 途经没有限行城市，或路线方案未涉及限行区域
 *  1 途经包含有限行的城市
 *  3 [设置车牌] 已避让限行
 *  4 [设置车牌] 无法避开限行区域（本方案包含限行路段）
 */
@property (nonatomic) int status;

@end

/*!
 *  @brief  预估打车费
 */
@interface QMSTaxiFare : QMSBaseResult

/*!
 *  @brief  预估打车费用，单位：元
 */
@property (nonatomic) double fare;

@end

/*!
 *  @brief  路况信息
 */
@interface QMSTrafficCondition : QMSBaseResult

/*!
 *  @brief  阶段路线坐标点串
 */
@property (nonatomic, strong) NSArray <NSNumber *> *polyline_idx;

/*!
 *  @brief  距离
 */
@property (nonatomic, assign) double distance;

/*!
 *  @brief  路况级别 0:畅通 1:缓行 2:拥堵 3:无路况 4:严重拥堵
 */
@property (nonatomic, assign) int level;

/*!
 *  @brief  速度，单位 千米每小时.
 */
@property (nonatomic) double speed;

@end

/*!
 *  @brief  途径点
 */
@interface QMSRouteWayPoint : QMSBaseResult

/*!
 *  @brief  途经点名称
 */
@property (nonatomic, nullable, copy) NSString *title;

/*!
 *  @brief  途经点经纬度
 */
@property (nonatomic) CLLocationCoordinate2D location;

/*!
 *  @brief  距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  所在的点串索引.
 */
@property (nonatomic) NSInteger polyline_idx;

@end


/*!
 *  @brief  路径规划的路线方案
 */
@interface QMSRoutePlan : QMSBaseResult

/*!
 *  @brief  方案交通方式. 固定值, kQMSRouteWalkingMode:步行
 */
@property (nonatomic ,copy) NSString *mode;

/*!
 *  @brief  方案整体距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  方案估算时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  方案整体方向描述
 */
@property (nonatomic, nullable, copy) NSString *direction;

/*!
 *  @brief  方案路线坐标点串, 导航方案经过的点, 每个step中会根据索引取得自己所对应的路段, 类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, copy) NSArray <NSValue *> *polyline;

/*!
 *  @brief  标记如何通过一个路段的信息，类型为QMSRouteStep
 */
@property (nonatomic, nullable, copy) NSArray <QMSRouteStep *> *steps;

/*!
 *  @brief  限行信息
 */
@property (nonatomic, nullable, strong) QMSDriveRestriction *restriction;

/*!
 *  @brief  预估打车费
 */
@property (nonatomic, nullable, strong) QMSTaxiFare *taxi_fare;

/*!
 *  @brief  预估过路费
 */
@property (nonatomic, assign) CGFloat toll;

/*!
 *  @brief  收费路段整体距离 单位:米, 需在额外字段added_fields中填入toll_distance
 */

@property (nonatomic) CGFloat toll_distance;

/*!
 *  @brief  预估红绿灯数
 */
@property (nonatomic, assign) int traffic_light_count;

/*!
 *  @brief  中文标签
 */
@property (nonatomic, nullable, copy) NSArray <NSString *> *tags;

/*!
 *  @brief  路况信息，对象中每个子项为一个QMSTrafficCondition对象
 */
@property (nonatomic, nullable, copy) NSArray <QMSTrafficCondition *> *speed;
/*!
 *  @brief  途经点，顺序与输入waypoints一致，输入此参数时，才会有此结点返回, 类型为QMSRouteWayPoint
 */
@property (nonatomic, nullable, copy) NSArray <QMSRouteWayPoint *> *waypoints;

/*!
 *	@brief 途径城市列表，元素为 QMSRoutePlanCityInfo, 需在额外字段added_fields中填入cities
 */
@property (nonatomic, nullable, copy) NSArray <QMSRoutePlanCityInfo *> *cities;

@end


/*!
 *  @brief  路径规划的路线步骤
 */
@interface QMSRouteStep : QMSBaseResult

/*!
 *  @brief  阶段路线描述
 */
@property (nonatomic, copy) NSString *instruction;

/*!
 *  @brief  阶段路线路名(非必有)
 */
@property (nonatomic, nullable, copy) NSString *road_name;

/*!
 *  @brief  阶段路线方向(如"南", 非必有)
 */
@property (nonatomic, nullable, copy) NSString *dir_desc;

/*!
 *  @brief  阶段路线距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  阶段路线末尾动作(如 ”向南转“, 非必有)
 */
@property (nonatomic, nullable, copy) NSString *act_desc;

/*!
 * @brief 末尾辅助动作(如 "到达终点", 非必有)
 */
@property (nonatomic, nullable, copy) NSString *accessorial_desc;

/*!
 *  @brief  阶段路线坐标点串在方案路线坐标点串的位置
 *
 *  从经纬度数组中 根据索引查询这一段路的途经点。 在WebService原始接口做了除2处理, 数据类型为NSNumber
 *  polyline_idx[0]:起点索引 
 *  polyline_idx[1]:终点索引
 */
@property (nonatomic, copy) NSArray <NSNumber *> *polyline_idx;

/*!
 *  @brief  阶段路线的步行设施类型（type），包含：0普通道路，1过街天桥，2地下通道，3人行横道
 */
@property (nonatomic, assign) int type;

@end

#pragma mark - Driving

/*!
 *  @brief  驾车路线检索结果
 */
@interface QMSDrivingRouteSearchResult : QMSSearchResult

/*!
 *  @brief  路径规划方案数组, 元素类型为QMSRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSRoutePlan *> *routes;

@end

#pragma mark - Trucking

/*!
 *  @brief  货车路线检索结果
 */
@interface QMSTruckingTrafficCondition : QMSTrafficCondition

@end

/*!
 *  @brief  货车路径规划的路线步骤
 */
@interface QMSTruckingRouteStep : QMSBaseResult

/*!
 *  @brief  阶段路线描述
 */
@property (nonatomic, nullable, copy) NSString *instruction;

/*!
 *  @brief  阶段路线路名(非必有)
 */
@property (nonatomic, nullable, copy) NSString *road_name;

/*!
 *  @brief  阶段路线方向(如"南", 非必有)
 */
@property (nonatomic, nullable, copy) NSString *dir_desc;

/*!
 *  @brief  阶段路线距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  阶段路线末尾动作(如 ”向南转“, 非必有)
 */
@property (nonatomic, nullable, copy) NSString *act_desc;

/*!
 *  @brief  阶段路线坐标点串在方案路线坐标点串的位置
 *
 *  从经纬度数组中 根据索引查询这一段路的途经点。 在WebService原始接口做了除2处理, 数据类型为NSNumber
 *  polyline_idx[0]:起点索引
 *  polyline_idx[1]:终点索引
 */
@property (nonatomic, nullable, copy) NSArray <NSNumber *> *polyline_idx;

/*!
 *  @brief  补充描述.
 */
@property (nonatomic, nullable, copy) NSString *accessorial_desc;

@end

/*!
 *  @brief  货车路径规划的路线方案
 */
@interface QMSTruckingRoutePlan : QMSBaseResult

/*!
 *  @brief  模式，固定为 @"TRUCKING"
 */
@property (nonatomic, copy) NSString *mode;

/*!
 *  @brief  距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  预估红绿灯数
 */
@property (nonatomic, assign) int traffic_light_count;

/*!
 *  @brief  预估过路费
 */
@property (nonatomic) CGFloat toll;

/*!
 *  @brief  方案路线坐标点串, 导航方案经过的点, 每个step中会根据索引取得自己所对应的路段, 类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, nullable, copy) NSArray <NSValue *> *polyline;

/*!
 *  @brief  中文标签
 */
@property (nonatomic, nullable, copy) NSArray <NSString *> *tags;

/*!
 *  @brief  限行信息
 */
@property (nonatomic, nullable, strong) QMSDriveRestriction *restriction;

/*!
 *  @brief  标记如何通过一个路段的信息，类型为QMSTruckingRouteStep
 */
@property (nonatomic, nullable, copy) NSArray <QMSTruckingRouteStep *> *steps;

/*!
 *  @brief  路况信息.
 */
@property (nonatomic, nullable, copy) NSArray <QMSTruckingTrafficCondition *> *speed;

/*!
 *  @brief  收费路段整体距离 单位:米, 需在额外字段added_fields中填入toll_distance
 */

@property (nonatomic) CGFloat toll_distance;

/*!
 *	@brief 途径城市列表，元素为 QMSRoutePlanCityInfo, 需在额外字段added_fields中填入cities
 */
@property (nonatomic, nullable, copy) NSArray <QMSRoutePlanCityInfo *> *cities;

@end

/*!
 *  @brief  货车路线检索结果
 */
@interface QMSTruckingRouteSearchResult : QMSSearchResult

/*!
 *  @brief  路径规划方案数组, 元素类型为QMSTruckingRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSTruckingRoutePlan *> *routes;

@end

#pragma mark - Busing

@class QMSBusingSegmentRoutePlan, QMSBusingRouteTransitLine;
/*!
 *  @brief  公交出行方案
 */
@interface QMSBusingRoutePlan : QMSBaseResult

/*!
 *  @brief  距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  路线bounds，用于显示地图时使用
 */
@property (nonatomic, copy) NSString *bounds;

/*!
 *  @brief  分段描述 类型为:QMSBusingSegmentRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSBusingSegmentRoutePlan *> *steps;

/*!
 *  @brief  中文标签
 */
@property (nonatomic, nullable, strong) NSArray <NSString *> *tags;

@end


/*!
 *  @brief  公交分段方案
 */
@interface QMSBusingSegmentRoutePlan : QMSBaseResult

/*!
 *  @brief  标记路径规划类型 "DRIVING":驾车 "WALKING":步行 "TRANSIT":公交
 */
@property (nonatomic ,copy) NSString *mode;

/*!
 *  @brief  距离 单位:米
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  时间 单位:分钟 四舍五入
 */
@property (nonatomic) CGFloat duration;

/*!
 *  @brief  阶段路线所花费用
 */
@property (nonatomic) CGFloat price DEPRECATED_ATTRIBUTE;

/*!
 *  @brief  方向描述
 */
@property (nonatomic) NSString *direction;

/*!
 *  @brief  路线坐标点串, 导航方案经过的点, 每个step中会根据索引取得自己所对应的路段, 类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, copy) NSArray <NSValue *> *polyline;

/*!
 *  @brief  同个路段多趟车的选择, 元素类型QMSBusingRouteTransitLine
 */
@property (nonatomic, copy) NSArray <QMSBusingRouteTransitLine *> *lines;

@end

/*!
 *  @brief  出入口
 */
@interface QMSStationEntrance : QMSBaseResult

/*!
 *  @brief  id
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  标题
 */
@property (nonatomic, copy) NSString *title;

@end

/*!
 *  @brief  上车点/下车点
 */
@interface QMSBusStation : QMSBaseResult

/*!
 *  @brief  id
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  站点名字
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  站点位置
 */
@property (nonatomic) CLLocationCoordinate2D location;

/*!
 *  @brief  出入口. 经停站时此属性为nil
 */
@property (nonatomic, strong) QMSStationEntrance *exit;

@end

/*!
 *  @brief  公交路线信息
 */
@interface QMSBusingRouteTransitLine : QMSBaseResult


/*!
 *  @brief  交通工具
 */
@property (nonatomic, copy) NSString *vehicle;

/*!
 *  @brief  id
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  距离(米)
 */
@property (nonatomic) CGFloat distance;

/*!
 *  @brief  预计耗时(分钟)
 */
@property (nonatomic) NSTimeInterval duration;

/*!
 *  @brief  阶段路线所花费用
 */
@property (nonatomic) CGFloat price;

/*!
 *  @brief  标题
 */
@property (nonatomic, copy) NSString *title;

/*!
 *  @brief  途经点数组，类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, copy) NSArray <NSValue *> *polyline;

/*!
 *  @brief  经停站数目
 */
@property (nonatomic) NSInteger station_count;

/*!
 *  @brief  上车站
 */
@property (nonatomic, strong) NSArray <QMSBusStation *> *stations;

/*!
 *  @brief  目的地地址
 */
@property (nonatomic, strong) QMSStationEntrance *destination;

/*!
 *  @brief  上车站
 */
@property (nonatomic, strong) QMSBusStation *geton;

/*!
 *  @brief  下车站
 */
@property (nonatomic, strong) QMSBusStation *getoff;

/*!
 *  @brief  线路运营状态，取值范围: 300:正常; 301:可能错过末班车; 302:首班车还未发出; 303:停运
 */
@property (nonatomic, assign) int running_status;

@end

/*!
 *  @brief  公交路径规划结果
 */
@interface QMSBusingRouteSearchResult : QMSSearchResult

/*!
 *  @brief  路径规划方案数组, 元素类型QMSBusingRoutePlan
 */
@property (nonatomic, copy) NSArray <QMSBusingRoutePlan *> *routes;

@end


#pragma mark - QMSDistrictSearchResult

/*!
 *  @brief  行政区划检索的结果的基类，请使用子类QMSDistrictSearchResult
 */
@interface QMSDistrictBaseSearchResult : QMSSearchResult

/*!
 *  @brief  行政区划数据版本，用于定期更新
 */
@property (nonatomic, copy) NSString *data_version;

@end

/*!
 *  @brief  表示单个行政区划信息的数据结构
 */
@interface QMSDistrictData : QMSBaseResult

/*!
 *  @brief  行政区划唯一标识
 *  注：省直辖地区，在数据表现上有一个重复的虚拟节点（其id最后两位为99），其目的是为了表明省直辖关系而增加的，开发者可根据实际需要选用
 */
@property (nonatomic, copy) NSString *id_;

/*!
 *  @brief  简称，如“内蒙古”
 */
@property (nonatomic, copy) NSString *name;

/*!
 *  @brief  全称，如“内蒙古自治区”
 */
@property (nonatomic, copy) NSString *fullname;

/*!
 *  @brief  中心点坐标(经纬度)
 */
@property (nonatomic, assign) CLLocationCoordinate2D location;

/*!
 *  @brief  行政区划拼音，每一下标为一个字的全拼，如：["nei","meng","gu"]
 */
@property (nonatomic, nullable, copy) NSArray <NSString *> *pinyin;

/*!
 *  @brief  子级行政区划在下级数组中的下标位置
 */
@property (nonatomic, nullable, copy) NSArray <NSNumber *> *cidx;

/*!
 *  @brief  行政区域轮廓坐标点串,类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, copy) NSArray *polygon __attribute__ ((deprecated("use @property (nonatomic, copy) NSArray *polygons instead")));

/*!
 *  @brief  一个或多个行政区域轮廓坐标点串数组,元素类型为encode的CLLocationCoordinate2D
 */
@property (nonatomic, nullable, copy) NSArray <NSArray <NSValue *> *> *polygons;

@end

/*!
 *  @brief  行政区划检索的结果
 */
@interface QMSDistrictSearchResult : QMSDistrictBaseSearchResult

/*!
 *  @brief  结果数组，第0项，代表一级行政区划，第1项代表二级行政区划，以此类推；使用getchildren接口时，仅为指定父级行政区划的子级
 *          元素类型包含QMSDistrictData元素的数组
 */
@property (nonatomic, copy) NSArray <NSArray <QMSDistrictData *> *> *result;

@end

NS_ASSUME_NONNULL_END
