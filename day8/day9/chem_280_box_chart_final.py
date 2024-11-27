import numpy as np
import matplotlib.pyplot as plt

def add_labels(x,y):
    for i in range(3):
        plt.text(x[i], y[i], y[i], ha = 'center')


psl_times = np.array([4.287,4.522,4.554,37.7,37.457,36.128,78.853,73.614,73.608]).reshape(3, 3).mean(axis=1)
numpy_times = np.array([1.247,1.099,1.078,4.468,4.424,4.471,8.331,8.259,9.075]).reshape(3, 3).mean(axis=1)
cpp_times = np.array([0.868,0.891,0.905,7.918,7.862,8.983,17.52,15.878,17.692]).reshape(3, 3).mean(axis=1)


bar_width = 0.20
bar1 = np.arange(3)
bar2 = [x + bar_width for x in bar1]
bar3 = [x + bar_width for x in bar2]


fig, ax = plt.subplots(figsize=(10, 8))

ax.bar(bar1, psl_times, color='teal', width=bar_width, edgecolor='white', label='Python')
add_labels(bar1, np.round(psl_times, 3))

ax.bar(bar2, numpy_times, color='mediumseagreen', width=bar_width, edgecolor='white', label='NumPy')
add_labels(bar2, np.round(numpy_times, 3))

ax.bar(bar3, cpp_times, color='cornflowerblue', width=bar_width, edgecolor='white', label='C++')
add_labels(bar3, np.round(cpp_times, 3))


plt.xlabel('Number of Steps', fontweight='bold', fontsize=15)
plt.ylabel('Time (seconds)', fontweight='bold', fontsize=15)
plt.xticks([r + bar_width for r in range(3)], ['2500', '25000', '50000'])
plt.legend()


plt.show()