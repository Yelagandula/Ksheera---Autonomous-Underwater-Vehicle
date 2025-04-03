import random
import csv

# Define the valid ranges for each parameter
temperature_range = (10, 15)
salinity_range = (30, 35)
oxygen_range = (5, 8)
ph_range = (7.0, 8.5)
turbidity_range = (0.1, 1.0)

# Generate 10,000 dummy data points with a balanced distribution
data = []
high_count = 0
low_count = 0
total_data_points = 10000
desired_high_percentage = 0.5

while high_count < total_data_points * desired_high_percentage or low_count < total_data_points * (1 - desired_high_percentage):
    hour = random.randint(1, 24)
    temperature = round(random.uniform(*temperature_range), 1)
    salinity = round(random.uniform(*salinity_range), 1)
    oxygen = round(random.uniform(*oxygen_range), 1)
    ph = round(random.uniform(*ph_range), 1)
    turbidity = round(random.uniform(*turbidity_range), 1)
    fish_population = 'High' if (temperature >= 10 and temperature <= 15 and
                                salinity >= 30 and salinity <= 35 and
                                oxygen >= 5 and oxygen <= 8 and
                                ph >= 7.0 and ph <= 8.5 and
                                turbidity >= 0.1 and turbidity <= 1.0) else 'Low'
    
    if fish_population == 'High' and high_count < total_data_points * desired_high_percentage:
        high_count += 1
        data.append([hour, temperature, salinity, oxygen, ph, turbidity, fish_population])
    elif fish_population == 'Low' and low_count < total_data_points * (1 - desired_high_percentage):
        low_count += 1
        data.append([hour, temperature, salinity, oxygen, ph, turbidity, fish_population])

# Write data to a CSV file
with open('ocean_data.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Hour', 'Temperature (°C)', 'Salinity (ppt)', 'Oxygen levels (mg/L)', 'pH levels', 'Turbidity (NTU)', 'Fish population'])
    writer.writerows(data)
