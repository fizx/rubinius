require File.dirname(__FILE__) + '/../../spec_helper'
require 'stringio'
require File.dirname(__FILE__) + "/shared/readchar"

describe "StringIO#readchar" do
  it_behaves_like :stringio_readchar, :readchar

  it "reads the next 8-bit byte from self's current position" do
    io = StringIO.new("example")

    io.send(@method).should == ?e

    io.pos = 4
    io.send(@method).should == ?p
  end
end

describe "StringIO#readchar when self is not readable" do
  it_behaves_like :stringio_readchar_not_readable, :readchar
end
