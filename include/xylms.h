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
	stu_num 	= 0,
	stu_id          = 1,
	stu_name        = 2,
	stu_sex         = 3,
	stu_class       = 4,
	stu_birthday    = 5,
	stu_qq          = 6,
	stu_phone1      = 7,
	stu_phone2      = 8,
	stu_mail        = 9,
	stu_blog        = 10,
	stu_where_to_go = 11,
	stu_other_info  = 12
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
