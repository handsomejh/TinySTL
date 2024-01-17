#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// ���ͷ�ļ�������ȡ������Ϣ

#include <type_traits>
#include<vector>


namespace mystl {

	// �����ṹ��
	template <class T, T v>
	struct m_integral_constant {
		static constexpr T value = v;
	};

	// ����ģ�壬���ڴ����������͵ı���ʱ����
	template <bool b>
	using m_bool_constant = m_integral_constant<bool, b>;

	// ����ģ�壬��ʾtrue��false�ı���ʱ����
	typedef m_bool_constant<true> m_true_type;
	typedef m_bool_constant<false> m_false_type;

	/*****************************************************************************************/


	// --- forward declaration begin
	template <class T1, class T2>
	struct pair;
	// --- forward declaration end

	// �жϸ��������Ƿ��� mystl::pair ���͵����Թ���
	template <class T>
	struct is_pair : mystl::m_false_type {};

	template <class T1, class T2>
	struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};
	
}

#endif // !MYTINYSTL_TYPE_TRAITS_H_