#pragma once

template <typename PairTKey, typename PairTValue>
class KeyValuePair {
public:
	PairTKey key;
	PairTValue value;
	KeyValuePair() :key(), value() {}
	KeyValuePair(const PairTKey key, const PairTValue value)
		:key(key), value(value) {
	}
	PairTValue& operator[](PairTKey key) 
	{
		if (key == this->key)
			return value;

		assert(!"This key is not exit!");
	}
};