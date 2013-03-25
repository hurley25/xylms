// =====================================================================================
// 
//       Filename:  xylms.h
//
//    Description:  项目主头文件
//
//        Version:  1.0
//        Created:  2013年03月21日 14时16分21秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef XYLMS_H_
#define XYLMS_H_

// 数据表项目位置的枚举定义
enum {
	stu_id          = 0,
	stu_name        = 1,
	stu_sex         = 2,
	stu_class       = 3,
	stu_birthday    = 4,
	stu_qq          = 5,
	stu_phone1      = 6,
	stu_phone2      = 7,
	stu_mail        = 8,
	stu_blog        = 9,
	stu_where_to_go = 10,
	stu_other_info  = 11
};

// 主窗口列表控件的枚举定义
enum {
	widget_new_join = 0,
	widget_grade    = 1,
	widget_manage   = 2,
	widget_set      = 3
};

// 延时函数
void Sleep(unsigned int msec);

//  连接数据库
bool createConnect();

#endif // XYLMS_H_
