#pragma once

namespace pointer {
	template <typename T>
	class unique_ptr {
	public:
		explicit unique_ptr(T* ptr) noexcept : ptr(ptr) {};
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
		~unique_ptr() { delete ptr; }

		T& operator*() const noexcept { return *ptr; }
		unique_ptr& operator=(const unique_ptr&) = delete;
		unique_ptr& operator=(unique_ptr&& other) noexcept {
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;

			return *this;
		}

		T* release() noexcept {
			T* temp = ptr;
			ptr = nullptr;
			return temp;
		}

	private:
		T* ptr = nullptr;
	};
}