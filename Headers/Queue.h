#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Deque.h"
#include "Functional.h"
#include "Vector.h"

namespace TinySTL{
	//class of queue
	template<class T, class Container = TinySTL::deque<T>>
	class queue{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;
	private:
		Container container_;
	public:
		queue(){}
		explicit queue(const container_type& ctnr) :container_(ctnr){}

		bool empty() const{ return container_.empty(); }
		size_type size() const{ return container_.size(); }
		reference& front(){ return container_.front(); }
		const_reference& front() const{ return container_.front(); }
		reference& back(){ return container_.back(); }
		const_reference& back() const{ return container_.back(); }
		void push(const value_type& val){ container_.push_back(val); }
		void pop(){ container_.pop_front(); }
		void swap(queue& x){ container_.swap(x.container_); }
	public:
		template <class T, class Container>
		friend bool operator== (const queue<T, Container>& lhs, const queue<T, Container>& rhs);
		template <class T, class Container>
		friend bool operator!= (const queue<T, Container>& lhs, const queue<T, Container>& rhs);
		template <class T, class Container>
		friend void swap(queue<T, Container>& x, queue<T, Container>& y);
	};
	template <class T, class Container>
	bool operator== (const queue<T, Container>& lhs, const queue<T, Container>& rhs){
		return lhs.container_ == rhs.container_;
	}
	template <class T, class Container>
	bool operator!= (const queue<T, Container>& lhs, const queue<T, Container>& rhs){
		return lhs.container_ != rhs.container_;
	}
	template <class T, class Container>
	void swap(queue<T, Container>& x, queue<T, Container>& y){
		TinySTL::swap(x.container_, y.container_);
	}
}

#endif