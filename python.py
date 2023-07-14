import math

def calculate_min_time(M, N, T1, T2):
    time_per_processor = T1 * (N / M)  # 每个处理器的计算时间开销
    merge_time = math.log2(M) * T2  # 归并操作的时间开销
    total_time = time_per_processor + merge_time  # 总时间开销
    return int(total_time)  # 返回最小总时间开销（取整）

# 输入
M, N, T1, T2 = 7, 10000, 10, 5

# 调用函数计算最小总时间开销
min_time = calculate_min_time(M, N, T1, T2)

# 输出结果
print(min_time)