import pandas as pd
import matplotlib.pyplot as plt
import pytz

file_name = "TEMP.CSV"

# Read the CSV file into a DataFrame
df = pd.read_csv(file_name, header=None, names=['timestamp', 'sensor_name', 'temperature'])

# Convert the 'timestamp' column to datetime format
df['timestamp'] = pd.to_datetime(df['timestamp'], format='%H:%M:%S %d/%m/%Y')

# Convert timestamps from UTC to local time (London time)
london_tz = pytz.timezone('Europe/London')
df['timestamp'] = df['timestamp'].dt.tz_localize('UTC').dt.tz_convert(london_tz)

# Get unique sensor names
sensor_names = df['sensor_name'].unique()

# Plot temperature values over time for each sensor
for sensor_name in sensor_names:
    sensor_data = df[df['sensor_name'] == sensor_name]
    plt.plot(sensor_data['timestamp'], sensor_data['temperature'], label=sensor_name)

# Set plot title and labels
plt.title('Temperature Values Over Time (London Time)')
plt.xlabel('Timestamp')
plt.ylabel('Temperature (Celsius)')
plt.legend()

# Rotate x-axis tick labels for better readability
plt.xticks(rotation=45)

# Show the plot
plt.tight_layout()
plt.show()