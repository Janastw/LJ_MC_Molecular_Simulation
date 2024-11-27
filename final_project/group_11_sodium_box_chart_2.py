import numpy as np
import matplotlib.pyplot as plt

def add_labels(x,y):
    for i in range(3):
        plt.text(x[i], y[i], y[i], ha = 'center')


psl_times = np.array([3.743, 3.677, 3.877, 33.064, 35.396, 34.016, 70.43, 68.033, 77.877]).reshape(3, 3).mean(axis=1)
numpy_times = np.array([1.157, 0.869, 0.91, 3.458, 3.532, 3.704, 6.493, 7.009, 6.955]).reshape(3, 3).mean(axis=1)
cpp_times = np.array([0.761, 0.779, 0.782, 6.997, 6.834, 6.938, 14.074, 14.55, 14.461]).reshape(3, 3).mean(axis=1)
cpp_O3_times = np.array([0.208, 0.221, 0.22, 1.954, 1.934, 2.05, 3.704, 4.008, 3.848]).reshape(3,3).mean(axis=1)

bar_width = 0.20
bar1 = np.arange(3)
bar2 = [x + bar_width for x in bar1]
bar3 = [x + bar_width for x in bar2]
bar4 = [x + bar_width for x in bar3]


fig, ax = plt.subplots(figsize=(10, 8))

ax.bar(bar1, psl_times, color='teal', width=bar_width, edgecolor='white', label='Python')
add_labels(bar1, np.round(psl_times, 3))

ax.bar(bar2, numpy_times, color='mediumseagreen', width=bar_width, edgecolor='white', label='NumPy')
add_labels(bar2, np.round(numpy_times, 3))

ax.bar(bar3, cpp_times, color='cornflowerblue', width=bar_width, edgecolor='white', label='C++')
add_labels(bar3, np.round(cpp_times, 3))

ax.bar(bar4, cpp_O3_times, color='slateblue', width=bar_width, edgecolor='white', label='C++ -O3')
add_labels(bar4, np.round(cpp_O3_times, 3))

plt.xlabel('Number of Steps', fontweight='bold', fontsize=15)
plt.ylabel('Time (seconds)', fontweight='bold', fontsize=15)
plt.xticks([r + bar_width for r in range(3)], ['2500', '25000', '50000'])
plt.legend()


plt.show()