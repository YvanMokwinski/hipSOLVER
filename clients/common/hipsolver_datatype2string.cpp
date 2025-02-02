/* ************************************************************************
 * Copyright 2020-2021 Advanced Micro Devices, Inc.
 * ************************************************************************ */

#include "../include/hipsolver_datatype2string.hpp"

/* ============================================================================================ */
/*  Convert hipsolver constants to lapack char. */

char hipsolver2char_operation(hipsolverOperation_t value)
{
    switch(value)
    {
    case HIPSOLVER_OP_N:
        return 'N';
    case HIPSOLVER_OP_T:
        return 'T';
    case HIPSOLVER_OP_C:
        return 'C';
    default:
        throw std::invalid_argument("Invalid enum");
    }
}

char hipsolver2char_fill(hipsolverFillMode_t value)
{
    switch(value)
    {
    case HIPSOLVER_FILL_MODE_UPPER:
        return 'U';
    case HIPSOLVER_FILL_MODE_LOWER:
        return 'L';
    default:
        throw std::invalid_argument("Invalid enum");
    }
}

char hipsolver2char_side(hipsolverSideMode_t value)
{
    switch(value)
    {
    case HIPSOLVER_SIDE_LEFT:
        return 'L';
    case HIPSOLVER_SIDE_RIGHT:
        return 'R';
    default:
        throw std::invalid_argument("Invalid enum");
    }
}

/* ============================================================================================ */
/*  Convert lapack char constants to hipsolver type. */

hipsolverStatus_t string2hipsolver_status(const std::string& value)
{
    return value == "HIPSOLVER_STATUS_SUCCESS"             ? HIPSOLVER_STATUS_SUCCESS
           : value == "HIPSOLVER_STATUS_NOT_INITIALIZED"   ? HIPSOLVER_STATUS_NOT_INITIALIZED
           : value == "HIPSOLVER_STATUS_ALLOC_FAILED"      ? HIPSOLVER_STATUS_ALLOC_FAILED
           : value == "HIPSOLVER_STATUS_INVALID_VALUE"     ? HIPSOLVER_STATUS_INVALID_VALUE
           : value == "HIPSOLVER_STATUS_MAPPING_ERROR"     ? HIPSOLVER_STATUS_MAPPING_ERROR
           : value == "HIPSOLVER_STATUS_EXECUTION_FAILED"  ? HIPSOLVER_STATUS_EXECUTION_FAILED
           : value == "HIPSOLVER_STATUS_INTERNAL_ERROR"    ? HIPSOLVER_STATUS_INTERNAL_ERROR
           : value == "HIPSOLVER_STATUS_NOT_SUPPORTED"     ? HIPSOLVER_STATUS_NOT_SUPPORTED
           : value == "HIPSOLVER_STATUS_ARCH_MISMATCH"     ? HIPSOLVER_STATUS_ARCH_MISMATCH
           : value == "HIPSOLVER_STATUS_HANDLE_IS_NULLPTR" ? HIPSOLVER_STATUS_HANDLE_IS_NULLPTR
           : value == "HIPSOLVER_STATUS_INVALID_ENUM"      ? HIPSOLVER_STATUS_INVALID_ENUM
           : value == "HIPSOLVER_STATUS_UNKNOWN"           ? HIPSOLVER_STATUS_UNKNOWN
                                                           : static_cast<hipsolverStatus_t>(-1);
}

hipsolverOperation_t char2hipsolver_operation(char value)
{
    switch(value)
    {
    case 'n':
    case 'N':
        return HIPSOLVER_OP_N;
    case 't':
    case 'T':
        return HIPSOLVER_OP_T;
    case 'c':
    case 'C':
        return HIPSOLVER_OP_C;
    default:
        throw std::invalid_argument("Invalid character");
    }
}

hipsolverFillMode_t char2hipsolver_fill(char value)
{
    switch(value)
    {
    case 'u':
    case 'U':
        return HIPSOLVER_FILL_MODE_UPPER;
    case 'l':
    case 'L':
        return HIPSOLVER_FILL_MODE_LOWER;
    default:
        throw std::invalid_argument("Invalid character");
    }
}

hipsolverSideMode_t char2hipsolver_side(char value)
{
    switch(value)
    {
    case 'l':
    case 'L':
        return HIPSOLVER_SIDE_LEFT;
    case 'r':
    case 'R':
        return HIPSOLVER_SIDE_RIGHT;
    default:
        throw std::invalid_argument("Invalid character");
    }
}
