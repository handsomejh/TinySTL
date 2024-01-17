#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

#include <type_traits>
#include<vector>


namespace mystl {

	// 辅助结构体
	template <class T, T v>
	struct m_integral_constant {
		static constexpr T value = v;
	};

	// 别名模板，用于创建布尔类型的编译时常量
	template <bool b>
	using m_bool_constant = m_integral_constant<bool, b>;

	// 别名模板，表示true和false的编译时常量
	typedef m_bool_constant<true> m_true_type;
	typedef m_bool_constant<false> m_false_type;

	/*****************************************************************************************/


	// --- forward declaration begin
	template <class T1, class T2>
	struct pair;
	// --- forward declaration end

	// 判断给定类型是否是 mystl::pair 类型的特性工具
	template <class T>
	struct is_pair : mystl::m_false_type {};

	template <class T1, class T2>
	struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};
	
}

#endif // !MYTINYSTL_TYPE_TRAITS_H_