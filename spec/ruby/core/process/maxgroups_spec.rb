require File.dirname(__FILE__) + '/../../spec_helper'

describe "Process.maxgroups" do
  it "returns the maximum number of gids allowed in the supplemental group access list" do
    Process.maxgroups.should be_kind_of(Fixnum)
  end

  it "sets the maximum number of gids allowed in the supplemental group access list" do
    n = Process.maxgroups
    Process.maxgroups = n + 1
    Process.maxgroups.should == n + 1
    Process.maxgroups = n
  end
end
