import matplotlib.pyplot as plt
from load_csv import load

def main():
    data = load("life_expectancy_years.csv")
    frData = data[data['country'] == 'France']
    years = frData.columns[1:]
    life = frData.values[0][1:]
    plt.plot(years, life, label='France')
    plt.title("Overly optimistic life expectancy projections in France")
    plt.xlabel('Year')
    plt.xticks(years[::40], rotation=45)
    plt.ylabel('Life expectancy')
    plt.tight_layout()
    plt.yticks(range(30, 101, 10))
    plt.show()
    
    
   

if __name__ == "__main__":
    main()