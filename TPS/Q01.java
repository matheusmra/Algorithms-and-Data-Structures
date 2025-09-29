package TP04;

class Jogo{
    private int id;
    private String name;
    private String releaseDate;
    private int estimatedOwners;
    private float price;
    private String[] supportedLanguages;
    private int metacriticScore;
    private int userScore;
    private int achievements;
    private String publishers;
    private String developers;
    private String[] categories;
    private String[] genres;
    private String[] tags;


    Jogo(){
        this.id = 0;
        this.name = null;
        this.releaseDate = null;
        this.estimatedOwners = 0;
        this.price = 0;
        this.supportedLanguages = null;
        this.metacriticScore = 0;
        this.userScore = 0;
        this.achievements = 0;
        this.publishers = null;
        this.developers = null;
        this.categories = null;
        this.genres = null;
        this.tags = null;
    }

    Jogo(int id,String name, String releaseDate, int estimatedOwners, float price
    , String[] supportedLanguages, int metacriticScore, int userScore, int achievements, String[] categories, String[] genres, String[] tags){
        this.id = id;
        this.name = name;
        this.releaseDate = releaseDate;
        this.estimatedOwners = estimatedOwners;
        this.price = price;
        this.supportedLanguages = new String[supportedLanguages.length];
        this.metacriticScore = metacriticScore;
        this.userScore = userScore;
        this.achievements = achievements;
        this.categories = new String[categories.length];
        this.genres = new String[genres.length];
        this.tags = new String[tags.length];
    }

    public int getJogoId(){
        return id;
    }

    public String getJogoName(){
        return name;
    }
}

public class Q01 {
    
}
