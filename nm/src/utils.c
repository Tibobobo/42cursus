#include "../include/ft_nm.h"

// #define MAX_BYTES 32

// void	changeEndian(void *ptr, size_t length)
// {
// 	uint8_t *bytes = (uint8_t *)ptr;
// 	uint8_t tmp[MAX_BYTES] = { 0 };

// 	if (length > MAX_BYTES)
// 		return;
	
// 	for (size_t i = 0; i < length; i++)
// 		tmp[i] = bytes[length - 1 - i];
// 	for (size_t i = 0; i < length; i++)
// 		bytes[i] = tmp[i];
// }

// uint16_t	ft_uint16(uint16_t n, bool littleEndian) {
// 	uint16_t res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(uint16_t));
// 	return (res);
// }

// uint32_t	ft_uint32(uint32_t n, bool littleEndian) {
// 	uint32_t res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(uint32_t));
// 	return (res);
// }

// uint64_t	ft_uint64(uint64_t n, bool littleEndian) {
// 	uint64_t res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(uint64_t));
// 	return (res);
// }

// unsigned int	ft_unsignedInt(unsigned int n, bool littleEndian) {
// 	unsigned int res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(unsigned int));
// 	return (res);
// }

// long unsigned int	ft_longUnsignedInt(long unsigned int n, bool littleEndian) {
// 	long unsigned int res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(long unsigned int));
// 	return (res);
// }

// int	ft_int(int n, bool littleEndian) {
// 	int res;

// 	res = n;
// 	if (!littleEndian)
// 		changeEndian(&res, sizeof(int));
// 	return (res);
// }
