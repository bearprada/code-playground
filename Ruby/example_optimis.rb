require 'net/http'
require 'json'

class CollaboratorFinder

    def initialize(owner, repo)
      @owner = owner
      @repo = repo
    end

    def find_contribution(sorted)
        collaborators = request("https://api.github.com/repos/#{@owner}/#{@repo}/collaborators")
        result = Array.new
        collaborators.each do |collaborator|
            repos = request("https://api.github.com/users/#{collaborator['login']}/repos")
            total = repos.inject(0) { |sum, repo| sum + repo['watchers'] }
            result.push({:login => collaborator['login'], :watchers => total})
        end
        return (sorted) ? result.sort_by { |d| d[:watchers] } : result
    end

    private
    def request(url)
        return JSON.parse(Net::HTTP.get(URI(url)))
    end
end

finder = CollaboratorFinder.new('rspec', 'rspec')
puts finder.find_contribution(true)